# Project Roadmap

This roadmap describes the intended technical direction of the project.
It does not represent a promise or a delivery schedule.
Priorities may change as the project evolves.
## Guiding Principles
- security over convenience
- cryptographic correctness over features
- explicit design over implicit behavior
- minimal trusted components
## Current State

- ✅ core account creation
- ✅ core account verification
- ✅ master key import
- ✅ identity derivation
- ⏳ authentication model

## Phase 1: Core Foundations

- finalize core module boundaries
- finalize crypto abstraction layer
- memory ownership enforcement
- account creation
- account import
- account verification
- core unit test coverage

## Phase 2: Cryptographic Protocol

- key agreement scheme
- authentication model
- multiple devices model
- private chat model
- message encryption format
- message order and time
- replay protection
- protocol versioning

## Phase 3: Networking Layer

- binary protocol framing
- client-server message flow
- request/response model
- transport abstraction
- connection lifecycle management

## Phase 4: Server Implementation

- encrypted data storage
- public key distribution
- message routing

## Phase 5: Client Integration

- minimal CLI client
- account lifecycle UX
- message send/receive flow

## Phase 6: Stabilization

- security review
- protocol audit
- performance profiling
- API freeze
- documentation refinement

## Phase 7: Server as separated project

- security improvements
- performance improvements
- blob store model

## Phase 8: Clients Development

- platform specific clients
- UI development

## Phase 9: Maintaining

- adding new features
- security reviews
- protocol maintaining