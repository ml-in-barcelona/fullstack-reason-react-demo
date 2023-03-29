# Benchmark

This directory contains the apps written in JavaScript (while the OCaml impl lives on server directory).
The same code is used for all benchmarks, translated to JavaScript in `node-express-js` and `bun-js`, and pointing to the
compiled JS from the `shared` directory in `node-express-rescript`.

The app consists in 5 simple nested components.

- `node-express-rescript`: Nodejs with Express running the JavaScript app's version compiled by Melange (containing Belt, ReScript stdlib and some React leftovers from the compilation)
- `node-express-js` Nodejs with Express running the JavaScript app's version (cleanup done by hand)
- `bun-js` Bun with JavaScript app's version (cleanup done by hand)
- `dream-reason-native` OCaml with Dream running server-reason-react app

## Running the benchmark

Command to run `wrk -t8 -c400 -d30s http://localhost:xxxx`

## Results

### node-express-rescript

  ```cd benchmark/node-express-rescript; NODE_ENV=production node index.js```

```sh
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency   109.35us   42.15us   1.68ms   75.40%
    Req/Sec     9.10k     2.11k   12.52k    51.08%
  2179657 requests in 30.10s, 5.96GB read

Requests/sec:  72414.39
Transfer/sec:    202.62MB
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
