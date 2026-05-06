# forge-chain-mempool-lab

`forge-chain-mempool-lab` is a C project for Blockchain tooling. It turns implement a C blockchain tooling project for mempool format conversion, using round-trip fixtures and lossless normalization checks into a small local model with readable fixtures and a direct verification command.

## Reading Forge Chain Mempool Lab

Start with the README, then open `metadata/project.json` to check the constants behind the examples. After that, `fixtures/cases.csv` shows the compact path and `examples/extended_cases.csv` gives a wider look at the same rule.

## Design Sketch

The core is a scoring model over demand, capacity, latency, risk, and weight. That keeps contract state, event replay, and invariant checks in one explicit decision path. The threshold is 166, with risk penalty 6, latency penalty 3, and weight bonus 2. The C implementation keeps headers, source, and assertions separate so bounds and types are easy to review.

## Purpose

The repository exists to keep a technical idea small enough to reason about. The implementation avoids external dependencies where possible, then uses fixtures to make changes easy to review.

## What It Does

- Uses fixture data to keep event replay changes visible in code review.
- Includes extended examples for invariant checks, including `recovery` and `degraded`.
- Documents settlement rules tradeoffs in `docs/operations.md`.
- Runs locally with a single verification command and no external credentials.
- Stores project constants and verification metadata in `metadata/project.json`.

## Fixture Notes

The examples are meant to be readable before they are exhaustive. They cover enough variation to show how latency and risk can pull a decision below the threshold.

## Files Worth Reading

- `src`: primary implementation
- `tests`: verification harness
- `fixtures`: compact golden scenarios
- `examples`: expanded scenario set
- `metadata`: project constants and verification metadata
- `docs`: operations and extension notes
- `scripts`: local verification and audit commands

## Setup

Install C and run the commands from the repository root. The project does not need credentials or a hosted service.

## Usage

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/verify.ps1
```

This runs the language-level build or test path against the compact fixture set.

## Verification

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/audit.ps1
```

The audit command checks repository structure and README constraints before it delegates to the verifier.

## Limits

The examples cover useful edges, not every edge. A larger version would add malformed-input tests, richer reports, and deeper domain parsers.

## Next Directions

- Add malformed input fixtures so the failure path is as visible as the happy path.
- Split the scoring constants into a typed configuration object and validate it before use.
- Add a comparison mode that shows how decisions change when one signal is adjusted.
- Add one more blockchain tooling fixture that focuses on a malformed or borderline input.
