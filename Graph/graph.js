import { useState, useEffect, useRef, useCallback } from "react";

const COLORS = {
  bg: "#0a0e1a",
  panel: "#111827",
  border: "#1e293b",
  unvisited: "#1e3a5f",
  unvisitedBorder: "#3b82f6",
  inQueue: "#854d0e",
  inQueueBorder: "#f59e0b",
  current: "#166534",
  currentBorder: "#22c55e",
  visited: "#1e1b4b",
  visitedBorder: "#6366f1",
  text: "#f1f5f9",
  dimText: "#64748b",
  edge: "#334155",
  activeEdge: "#22c55e",
  queueEdge: "#f59e0b",
};

const DEFAULT_EDGES = [[1,2],[1,3],[2,4],[2,5],[3,6],[3,7],[4,8]];
const NODE_COUNT = 8;

function buildAdjacency(edges, n) {
  const adj = {};
  for (let i = 1; i <= n; i++) adj[i] = [];
  for (const [u, v] of edges) {
    adj[u].push(v);
    adj[v].push(u);
  }
  return adj;
}

function computeLayout(n, edges) {
  // Tree-like layout for default, else circle
  const positions = {};
  // BFS-based level layout from node 1
  const adj = buildAdjacency(edges, n);
  const levels = {};
  const visited = new Set();
  const queue = [1];
  visited.add(1);
  levels[1] = 0;
  while (queue.length) {
    const node = queue.shift();
    for (const nb of adj[node]) {
      if (!visited.has(nb)) {
        visited.add(nb);
        levels[nb] = levels[node] + 1;
        queue.push(nb);
      }
    }
  }
  const levelGroups = {};
  for (const [node, lvl] of Object.entries(levels)) {
    if (!levelGroups[lvl]) levelGroups[lvl] = [];
    levelGroups[lvl].push(Number(node));
  }
  const maxLevel = Math.max(...Object.keys(levelGroups).map(Number));
  const W = 560, H = 340;
  for (const [lvl, nodes] of Object.entries(levelGroups)) {
    const y = 60 + (Number(lvl) / (maxLevel || 1)) * (H - 120);
    nodes.forEach((node, i) => {
      const x = (W / (nodes.length + 1)) * (i + 1);
      positions[node] = { x, y };
    });
  }
  return positions;
}

function bfsSteps(adj, src, n) {
  const steps = [];
  const visited = {};
  const queue = [];
  const inQueue = new Set();

  queue.push(src);
  inQueue.add(src);

  steps.push({
    queue: [...queue],
    visited: { ...visited },
    current: null,
    inQueue: new Set(inQueue),
    activeEdge: null,
    action: `Start: push source node ${src} into queue`,
    order: [],
  });

  const order = [];

  while (queue.length > 0) {
    const par = queue.shift();
    inQueue.delete(par);
    visited[par] = true;
    order.push(par);

    steps.push({
      queue: [...queue],
      visited: { ...visited },
      current: par,
      inQueue: new Set(inQueue),
      activeEdge: null,
      action: `Dequeue ${par} → mark visited, add to BFS order`,
      order: [...order],
    });

    for (const child of (adj[par] || [])) {
      if (!visited[child] && !inQueue.has(child)) {
        inQueue.add(child);
        queue.push(child);
        steps.push({
          queue: [...queue],
          visited: { ...visited },
          current: par,
          inQueue: new Set(inQueue),
          activeEdge: [par, child],
          action: `Neighbor ${child} not visited → enqueue ${child}`,
          order: [...order],
        });
      } else {
        steps.push({
          queue: [...queue],
          visited: { ...visited },
          current: par,
          inQueue: new Set(inQueue),
          activeEdge: [par, child],
          action: visited[child]
            ? `Neighbor ${child} already visited → skip`
            : `Neighbor ${child} already in queue → skip`,
          order: [...order],
        });
      }
    }
  }

  steps.push({
    queue: [],
    visited: { ...visited },
    current: null,
    inQueue: new Set(),
    activeEdge: null,
    action: "✅ BFS complete!",
    order: [...order],
  });

  return steps;
}

function getNodeColor(node, step) {
  if (step.current === node) return { fill: COLORS.current, stroke: COLORS.currentBorder, glow: "#22c55e" };
  if (step.visited[node]) return { fill: COLORS.visited, stroke: COLORS.visitedBorder, glow: "#6366f1" };
  if (step.inQueue.has(node)) return { fill: COLORS.inQueue, stroke: COLORS.inQueueBorder, glow: "#f59e0b" };
  return { fill: COLORS.unvisited, stroke: COLORS.unvisitedBorder, glow: null };
}

export default function BFSVisualizer() {
  const [edgeInput, setEdgeInput] = useState("1-2, 1-3, 2-4, 2-5, 3-6, 3-7, 4-8");
  const [nodeCount, setNodeCount] = useState(8);
  const [srcNode, setSrcNode] = useState(1);
  const [edges, setEdges] = useState(DEFAULT_EDGES);
  const [adj, setAdj] = useState(() => buildAdjacency(DEFAULT_EDGES, NODE_COUNT));
  const [positions, setPositions] = useState(() => computeLayout(NODE_COUNT, DEFAULT_EDGES));
  const [steps, setSteps] = useState(() => bfsSteps(buildAdjacency(DEFAULT_EDGES, NODE_COUNT), 1, NODE_COUNT));
  const [stepIdx, setStepIdx] = useState(0);
  const [playing, setPlaying] = useState(false);
  const [speed, setSpeed] = useState(900);
  const intervalRef = useRef(null);

  const step = steps[stepIdx];

  const applyGraph = useCallback(() => {
    try {
      const parsed = edgeInput.split(",").map(e => {
        const parts = e.trim().split("-").map(Number);
        if (parts.length !== 2 || isNaN(parts[0]) || isNaN(parts[1])) throw new Error();
        return parts;
      });
      const newAdj = buildAdjacency(parsed, nodeCount);
      const newPos = computeLayout(nodeCount, parsed);
      const newSteps = bfsSteps(newAdj, srcNode, nodeCount);
      setEdges(parsed);
      setAdj(newAdj);
      setPositions(newPos);
      setSteps(newSteps);
      setStepIdx(0);
      setPlaying(false);
    } catch {
      alert("Invalid edge format. Use: 1-2, 1-3, ...");
    }
  }, [edgeInput, nodeCount, srcNode]);

  useEffect(() => {
    if (playing) {
      intervalRef.current = setInterval(() => {
        setStepIdx(i => {
          if (i >= steps.length - 1) { setPlaying(false); return i; }
          return i + 1;
        });
      }, speed);
    }
    return () => clearInterval(intervalRef.current);
  }, [playing, speed, steps.length]);

  const reset = () => { setStepIdx(0); setPlaying(false); };
  const prev = () => { setStepIdx(i => Math.max(0, i - 1)); setPlaying(false); };
  const next = () => { setStepIdx(i => Math.min(steps.length - 1, i + 1)); setPlaying(false); };

  const isActiveEdge = (u, v) =>
    step.activeEdge &&
    ((step.activeEdge[0] === u && step.activeEdge[1] === v) ||
     (step.activeEdge[0] === v && step.activeEdge[1] === u));

  return (
    <div style={{ background: COLORS.bg, minHeight: "100vh", fontFamily: "'Courier New', monospace", color: COLORS.text, padding: "24px 16px" }}>
      <div style={{ maxWidth: 720, margin: "0 auto" }}>

        {/* Header */}
        <div style={{ textAlign: "center", marginBottom: 24 }}>
          <div style={{ fontSize: 11, letterSpacing: 6, color: COLORS.dimText, textTransform: "uppercase", marginBottom: 6 }}>Algorithm Visualizer</div>
          <h1 style={{ fontSize: 28, fontWeight: 900, margin: 0, background: "linear-gradient(90deg, #22c55e, #3b82f6)", WebkitBackgroundClip: "text", WebkitTextFillColor: "transparent" }}>
            BFS — Breadth First Search
          </h1>
        </div>

        {/* Bug Fix Banner */}
        <div style={{ background: "#1c0a0a", border: "1px solid #7f1d1d", borderRadius: 8, padding: "10px 16px", marginBottom: 20, fontSize: 12 }}>
          <span style={{ color: "#f87171", fontWeight: 700 }}>🐛 BUG FIXED: </span>
          <span style={{ color: "#fca5a5" }}>
            <code style={{ background: "#2d0a0a", padding: "2px 6px", borderRadius: 4 }}>isVisited[child] == true</code>
            <span style={{ color: "#ef4444" }}> → </span>
            <code style={{ background: "#14532d", padding: "2px 6px", borderRadius: 4, color: "#86efac" }}>isVisited[child] = true</code>
            <span style={{ color: "#fca5a5" }}> (== is comparison, = is assignment)</span>
          </span>
        </div>

        {/* Graph Config */}
        <div style={{ background: COLORS.panel, border: `1px solid ${COLORS.border}`, borderRadius: 10, padding: 16, marginBottom: 20 }}>
          <div style={{ fontSize: 11, letterSpacing: 3, color: COLORS.dimText, marginBottom: 12, textTransform: "uppercase" }}>Graph Configuration</div>
          <div style={{ display: "flex", gap: 8, flexWrap: "wrap", alignItems: "flex-end" }}>
            <div style={{ flex: 1, minWidth: 200 }}>
              <div style={{ fontSize: 11, color: COLORS.dimText, marginBottom: 4 }}>Edges (u-v, ...)</div>
              <input
                value={edgeInput}
                onChange={e => setEdgeInput(e.target.value)}
                style={{ width: "100%", background: "#0f172a", border: `1px solid ${COLORS.border}`, color: COLORS.text, padding: "7px 10px", borderRadius: 6, fontFamily: "inherit", fontSize: 12, boxSizing: "border-box" }}
              />
            </div>
            <div style={{ minWidth: 70 }}>
              <div style={{ fontSize: 11, color: COLORS.dimText, marginBottom: 4 }}>Nodes</div>
              <input type="number" min={2} max={20} value={nodeCount}
                onChange={e => setNodeCount(Number(e.target.value))}
                style={{ width: "100%", background: "#0f172a", border: `1px solid ${COLORS.border}`, color: COLORS.text, padding: "7px 10px", borderRadius: 6, fontFamily: "inherit", fontSize: 12 }}
              />
            </div>
            <div style={{ minWidth: 70 }}>
              <div style={{ fontSize: 11, color: COLORS.dimText, marginBottom: 4 }}>Source</div>
              <input type="number" min={1} max={nodeCount} value={srcNode}
                onChange={e => setSrcNode(Number(e.target.value))}
                style={{ width: "100%", background: "#0f172a", border: `1px solid ${COLORS.border}`, color: COLORS.text, padding: "7px 10px", borderRadius: 6, fontFamily: "inherit", fontSize: 12 }}
              />
            </div>
            <button onClick={applyGraph}
              style={{ background: "#1d4ed8", border: "none", color: "white", padding: "8px 18px", borderRadius: 6, cursor: "pointer", fontFamily: "inherit", fontWeight: 700, fontSize: 12 }}>
              Apply
            </button>
          </div>
        </div>

        {/* SVG Graph */}
        <div style={{ background: COLORS.panel, border: `1px solid ${COLORS.border}`, borderRadius: 10, padding: 12, marginBottom: 16 }}>
          <svg width="100%" viewBox="0 0 560 360" style={{ display: "block" }}>
            <defs>
              {[1,2,...Array(nodeCount).keys()].map(i => i+1).map(id => {
                const c = getNodeColor(id, step);
                return c.glow ? (
                  <filter key={id} id={`glow${id}`}>
                    <feGaussianBlur stdDeviation="4" result="blur" />
                    <feMerge><feMergeNode in="blur" /><feMergeNode in="SourceGraphic" /></feMerge>
                  </filter>
                ) : null;
              })}
            </defs>

            {/* Edges */}
            {edges.map(([u, v], i) => {
              const pu = positions[u], pv = positions[v];
              if (!pu || !pv) return null;
              const active = isActiveEdge(u, v);
              return (
                <line key={i}
                  x1={pu.x} y1={pu.y} x2={pv.x} y2={pv.y}
                  stroke={active ? COLORS.activeEdge : COLORS.edge}
                  strokeWidth={active ? 2.5 : 1.5}
                  strokeDasharray={active ? "none" : "none"}
                  opacity={active ? 1 : 0.5}
                />
              );
            })}

            {/* Nodes */}
            {Array.from({ length: nodeCount }, (_, i) => i + 1).map(id => {
              const pos = positions[id];
              if (!pos) return null;
              const c = getNodeColor(id, step);
              return (
                <g key={id} filter={c.glow ? `url(#glow${id})` : undefined}>
                  <circle cx={pos.x} cy={pos.y} r={20} fill={c.fill} stroke={c.stroke} strokeWidth={2.5} />
                  <text x={pos.x} y={pos.y + 5} textAnchor="middle" fill="white" fontSize={13} fontWeight={700} fontFamily="Courier New">
                    {id}
                  </text>
                  {/* Order label */}
                  {step.order.indexOf(id) !== -1 && (
                    <text x={pos.x + 16} y={pos.y - 16} fill="#a78bfa" fontSize={10} fontWeight={700}>
                      #{step.order.indexOf(id) + 1}
                    </text>
                  )}
                </g>
              );
            })}
          </svg>
        </div>

        {/* Legend */}
        <div style={{ display: "flex", gap: 16, justifyContent: "center", marginBottom: 16, flexWrap: "wrap" }}>
          {[
            { color: COLORS.unvisitedBorder, fill: COLORS.unvisited, label: "Unvisited" },
            { color: COLORS.inQueueBorder, fill: COLORS.inQueue, label: "In Queue" },
            { color: COLORS.currentBorder, fill: COLORS.current, label: "Current" },
            { color: COLORS.visitedBorder, fill: COLORS.visited, label: "Visited" },
          ].map(({ color, fill, label }) => (
            <div key={label} style={{ display: "flex", alignItems: "center", gap: 6, fontSize: 11 }}>
              <div style={{ width: 14, height: 14, borderRadius: "50%", background: fill, border: `2px solid ${color}` }} />
              <span style={{ color: COLORS.dimText }}>{label}</span>
            </div>
          ))}
        </div>

        {/* Step Info */}
        <div style={{ background: COLORS.panel, border: `1px solid ${COLORS.border}`, borderRadius: 10, padding: 14, marginBottom: 16 }}>
          <div style={{ display: "flex", justifyContent: "space-between", alignItems: "center", marginBottom: 10 }}>
            <span style={{ fontSize: 11, color: COLORS.dimText, letterSpacing: 2, textTransform: "uppercase" }}>Step {stepIdx + 1} / {steps.length}</span>
            <div style={{ background: "#0f172a", borderRadius: 20, height: 6, flex: 1, margin: "0 16px" }}>
              <div style={{ background: "linear-gradient(90deg, #3b82f6, #22c55e)", height: 6, borderRadius: 20, width: `${((stepIdx + 1) / steps.length) * 100}%`, transition: "width 0.3s" }} />
            </div>
          </div>
          <div style={{ fontSize: 13, color: "#e2e8f0", marginBottom: 12, minHeight: 20 }}>▶ {step.action}</div>

          {/* Queue visualization */}
          <div style={{ display: "flex", gap: 8, alignItems: "center", flexWrap: "wrap" }}>
            <span style={{ fontSize: 11, color: COLORS.dimText, minWidth: 50 }}>QUEUE:</span>
            <div style={{ display: "flex", gap: 4, alignItems: "center" }}>
              <span style={{ color: COLORS.dimText, fontSize: 13 }}>front [</span>
              {step.queue.length === 0
                ? <span style={{ color: COLORS.dimText, fontStyle: "italic", fontSize: 12 }}>empty</span>
                : step.queue.map((n, i) => (
                    <span key={i} style={{ background: COLORS.inQueue, border: `1.5px solid ${COLORS.inQueueBorder}`, color: "#fef3c7", borderRadius: 5, padding: "3px 10px", fontSize: 13, fontWeight: 700 }}>{n}</span>
                  ))
              }
              <span style={{ color: COLORS.dimText, fontSize: 13 }}>] rear</span>
            </div>
          </div>

          {/* BFS Order */}
          {step.order.length > 0 && (
            <div style={{ display: "flex", gap: 8, alignItems: "center", marginTop: 10, flexWrap: "wrap" }}>
              <span style={{ fontSize: 11, color: COLORS.dimText, minWidth: 50 }}>ORDER:</span>
              <div style={{ display: "flex", gap: 4 }}>
                {step.order.map((n, i) => (
                  <span key={i} style={{ background: COLORS.visited, border: `1.5px solid ${COLORS.visitedBorder}`, color: "#c7d2fe", borderRadius: 5, padding: "3px 10px", fontSize: 13, fontWeight: 700 }}>{n}</span>
                ))}
              </div>
            </div>
          )}
        </div>

        {/* Controls */}
        <div style={{ display: "flex", gap: 10, justifyContent: "center", alignItems: "center", flexWrap: "wrap" }}>
          <button onClick={reset} style={btnStyle("#1e293b")}>⏮ Reset</button>
          <button onClick={prev} disabled={stepIdx === 0} style={btnStyle("#1e293b", stepIdx === 0)}>◀ Prev</button>
          <button onClick={() => setPlaying(p => !p)} style={btnStyle(playing ? "#166534" : "#1d4ed8")}>
            {playing ? "⏸ Pause" : "▶ Play"}
          </button>
          <button onClick={next} disabled={stepIdx === steps.length - 1} style={btnStyle("#1e293b", stepIdx === steps.length - 1)}>Next ▶</button>
          <div style={{ display: "flex", alignItems: "center", gap: 8, marginLeft: 8 }}>
            <span style={{ fontSize: 11, color: COLORS.dimText }}>Speed</span>
            <input type="range" min={200} max={1800} step={100} value={1800 - speed + 200}
              onChange={e => setSpeed(1800 - Number(e.target.value) + 200)}
              style={{ width: 80, accentColor: "#3b82f6" }} />
          </div>
        </div>

      </div>
    </div>
  );
}

function btnStyle(bg, disabled) {
  return {
    background: disabled ? "#1a1a2e" : bg,
    border: "1px solid #334155",
    color: disabled ? "#475569" : "white",
    padding: "8px 18px",
    borderRadius: 7,
    cursor: disabled ? "not-allowed" : "pointer",
    fontFamily: "'Courier New', monospace",
    fontWeight: 700,
    fontSize: 12,
    transition: "all 0.15s",
  };
}