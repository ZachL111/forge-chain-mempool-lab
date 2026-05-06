# Forge Chain Mempool Lab Walkthrough

I use this file as a small checklist before changing the C implementation.

| Case | Focus | Score | Lane |
| --- | --- | ---: | --- |
| baseline | event finality | 182 | ship |
| stress | nonce pressure | 179 | ship |
| edge | settlement risk | 177 | ship |
| recovery | proof depth | 152 | ship |
| stale | event finality | 259 | ship |

Start with `stale` and `recovery`. They create the widest contrast in this repository's fixture set, which makes them better review anchors than the middle cases.

`stale` is the optimistic case; use it to make sure the scoring path still rewards strong signal.
