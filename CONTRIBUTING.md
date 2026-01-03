# Contributing Guidelines

Thank you for your interest in contributing to this project.

This repository follows strict architectural, cryptographic, and
engineering principles. Contributions are expected to respect the
project’s philosophy and documented design decisions.
## Before You Start

Before submitting any contribution, please read the following documents:
- [docs/philosophy.md](docs/philosophy.md)
- [docs/architecture.md](docs/architecture.md)

For non-trivial changes, also review:
- [docs/rfc/](docs/rfc/)

Contributions that violate these documents will not be accepted.
## Contribution Types
The following types of contributions are welcome:
- bug fixes
- documentation improvements
- test additions
- performance improvements
- implementation of accepted RFCs

The following are **not accepted without prior discussion**:
- new cryptographic primitives
- changes to the trust model
- architectural refactoring
- protocol design changes

## RFC Process

Any change that affects:
- cryptography
- identity model
- protocol behavior
- module boundaries

**MUST** be proposed as an RFC in `docs/rfc/`.

RFCs should describe:
- the problem
- the proposed solution
- alternatives considered
- security implications

Implementation should only begin after the RFC is accepted.
## Development Workflow
All changes must follow the documented workflow:
- [docs/development/workflow.md](docs/development/workflow.md)
- [docs/development/commits.md](docs/development/commits.md)
### Summary
1. Fork the repository
2. Create a feature branch
3. Implement the change
4. Add or update tests
5. Update documentation if required
6. Submit a pull request
## Commit Policy

Commits must:
- be logically scoped
- build successfully
- include meaningful commit messages

Refer to:
- [docs/development/commits.md](docs/development/commits.md)
## Coding Standards

All code must follow the project coding rules:
- [docs/coding/style.md](docs/coding/style.md)
- [docs/coding/naming.md](docs/coding/naming.md)
- [docs/coding/error-handling.md](docs/coding/error-handling.md)

Submissions that violate these rules will be rejected.
## Testing Requirements

All non-trivial changes must include tests.
- Tests should mirror the project module structure
- New functionality must be covered by unit tests
- Bug fixes must include regression tests

See:
- [docs/development/testing.md](docs/development/testing.md)
## Review Process

Pull requests are reviewed with focus on:
- architectural correctness
- security implications
- clarity and maintainability
- consistency with project philosophy

PRs may be rejected if they:
- introduce unnecessary complexity
- violate documented boundaries
- prioritize convenience over security