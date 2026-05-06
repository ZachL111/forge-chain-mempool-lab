# forge-chain-mempool-lab

`forge-chain-mempool-lab` explores blockchain tooling with a small C codebase and local fixtures. The technical goal is to implement a C blockchain tooling project for mempool format conversion, using round-trip fixtures and lossless normalization checks.

## Purpose

The project exists to keep a narrow engineering decision visible and testable. For this repo, that decision is how event finality and settlement risk should influence a review result.

## Forge Chain Mempool Lab Review Notes

Start with `event finality` and `proof depth`. Those cases create the widest score spread in this repo, so they are the best quick check when the model changes.

## What Is Covered

- `fixtures/domain_review.csv` adds cases for event finality and nonce pressure.
- `metadata/domain-review.json` records the same cases in structured form.
- `config/review-profile.json` captures the read order and the two review questions.
- `examples/forge-chain-mempool-walkthrough.md` walks through the case spread.
- The C code includes a review path for `event finality` and `proof depth`.
- `docs/field-notes.md` explains the strongest and weakest cases.

## Implementation Notes

The fixture data drives the tests. The code stays thin, while `metadata/domain-review.json` and `config/review-profile.json` explain what each case is meant to protect.

The added C path is deliberately direct, with fixtures doing most of the explaining.

## Command

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/verify.ps1
```

## Audit Path

That command is also the regression path. It verifies the domain cases and catches mismatches between the CSV, metadata, and code.

## Limits

The fixture set is small enough to audit by hand. The next useful expansion is malformed input coverage, not extra surface area.
