PID=506586
sudo perf record -F 99 -p ${PID} -g -- sleep 30
sudo perf script > out.perf

# https://github.com/brendangregg/FlameGraph
~/Projects/FlameGraph/stackcollapse-perf.pl out.perf > out.folded
~/Projects/FlameGraph/flamegraph.pl out.folded > perf.svg