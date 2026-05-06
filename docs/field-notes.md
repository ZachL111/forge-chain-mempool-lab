# Field Notes

`forge-chain-mempool-lab` is easiest to review by starting with the fixture, not the prose.

The domain cases cover `event finality`, `nonce pressure`, `settlement risk`, and `proof depth`. They sit beside the smaller starter fixture so the project has both a compact scoring check and a domain-flavored review check.

The widest spread is between `event finality` and `proof depth`, so those are the first two cases I would preserve during a refactor.

The point is not to make the repository bigger. The point is to make the important judgment testable.
