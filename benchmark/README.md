# Benchmark

## Running the benchmark

Command to run `wrk -t8 -c400 -d30s http://localhost:xxxx`

## Results

### node-express-rescript

  ```cd benchmark/node-express-rescript; NODE_ENV=production node index.js```

```sh
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    40.82ms   10.45ms 188.76ms   85.29%
    Req/Sec     1.22k   267.70     1.51k    70.58%
  291638 requests in 30.08s, 270.62MB read
  Socket errors: connect 0, read 964, write 0, timeout 0
Requests/sec:   9695.68
Transfer/sec:      9.00MB
```

### node-express-js

  ```cd benchmark/node-express-js; NODE_ENV=production node index.js```

```sh
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    30.95ms   10.65ms 221.09ms   90.26%
    Req/Sec   650.73    443.99     1.57k    50.64%
  233002 requests in 30.09s, 216.21MB read

Requests/sec:   7742.55
Transfer/sec:      7.18MB
```

### bun-js

  ```cd benchmark/bun-js; NODE_ENV=production ~/bun/bin/bun run index.js```

```sh
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    22.85ms    5.24ms 120.22ms   95.59%
    Req/Sec     0.88k   492.74     2.31k    50.77%
  315018 requests in 30.10s, 257.46MB read

Requests/sec:  10464.64
Transfer/sec:      8.55MB
```

### dream-reason-native

  ```make server-start```

```sh
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency     4.35ms  462.82us  17.63ms   91.16%
    Req/Sec     4.60k     2.27k   18.12k    59.92%
  1648019 requests in 30.10s, 2.02GB read

Requests/sec:  54743.09
Transfer/sec:     68.60MB
```
