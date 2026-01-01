# Development Workflow

## Purpose
This document defines the development workflow for this repository.
Its goal is to ensure code quality, security, and long-term maintainability.
## Branching Model

- `master` — stable branch, always buildable
- `dev` — integration branch (optional)
- `feature/*` — feature development
- `fix/*` — bug fixes
- `refactor/*` — internal refactors
- `docs/*` — documentation changes

Direct commits to `master` are forbidden.
## Feature Development Flow
1. Create or update an RFC (if required)
2. Create a feature branch. Example: `feature/account-creation`
3. Implement the feature
4. Write tests
5. Update documentation
6. Open a Pull Request
## RFC Process
RFC is required for:
- new architecture components
- cryptography
- public APIs
- data formats
- security-sensitive logic

RFC lifecycle:
- Draft
- Approved
- Implemented
- Rejected

RFCs are stored in <a href="https://github.com/Wemis/messenger/tree/master/docs/design">docs/rfc</a>.
## Commit Rules
*Commit rules is available here* <a href=""https://github.com/Wemis/messenger/blob/master/docs/development/commits.md>commits.md</a>
## Pull Requests
PR requirements:
- Clear description of changes
- Reference to RFC
- Documentation updated if behavior changes

PR title example: `Implement RFC-001: Account Creation`
## Documentation Rules
Documentation must be updated when:
- public APIs change
- behavior changes
- new modules are added