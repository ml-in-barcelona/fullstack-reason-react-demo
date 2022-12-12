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

Command to run `wrk -t12 -c400 -d30s http://localhost:xxxx`

## Results

### node-express-rescript

  ```cd benchmark/node-express-rescript; NODE_ENV=production node index.js```

```sh
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    34.72ms   10.67ms 206.95ms   87.77%
    Req/Sec   578.38    387.12     2.34k    52.28%
  207023 requests in 30.10s, 282.13MB read
  Socket errors: connect 157, read 78, write 5, timeout 0
Requests/sec:   6877.41
Transfer/sec:      9.37MB
```

### node-express-js

  ```cd benchmark/node-express-js; NODE_ENV=production node index.js```

```sh
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    30.95ms   10.65ms 221.09ms   90.26%
    Req/Sec   650.73    443.99     1.57k    50.64%
  233002 requests in 30.09s, 216.21MB read
  Socket errors: connect 157, read 39, write 0, timeout 0
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
  Socket errors: connect 157, read 26, write 0, timeout 0
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
  Socket errors: connect 157, read 98, write 0, timeout 0
Requests/sec:  54743.09
Transfer/sec:     68.60MB
```
