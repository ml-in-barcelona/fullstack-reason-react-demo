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

Requests/sec:   9695.68
Transfer/sec:      9.00MB
```

### node-express-js

  ```cd benchmark/node-express-js; NODE_ENV=production node index.js```

```sh
    Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    30.89ms   11.23ms 206.66ms   93.11%
    Req/Sec     1.66k   321.02     2.02k    81.42%
  396545 requests in 30.09s, 524.91MB read

Requests/sec:  13176.71
Transfer/sec:     17.44MB
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

  ```make build-server-prod; _build/default/server/server.exe```

```sh
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency     6.15ms  598.15us  23.92ms   97.05%
    Req/Sec     8.17k     1.40k   75.44k    98.63%
  1951327 requests in 30.10s, 5.18GB read

Requests/sec:  64822.31
Transfer/sec:    176.12MB
```
