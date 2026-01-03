# Messenger Philosophy

## Overview

This messenger is designed as a **zero-trust communication system**.
No component of the system is trusted by default.
All trust is established exclusively through cryptography.

The primary goal of the project is to provide secure, verifiable,
and transparent communication without relying on centralized trust
assumptions.
## Zero-Trust Model

The system follows a strict zero-trust philosophy:

- The server is not trusted
- The network is not trusted
- Clients do not implicitly trust each other
- Trust is derived only from cryptographic verification

Every security guarantee must be enforceable and verifiable
cryptographically, not socially or institutionally.
## Cryptography as the Root of Trust

All identity and authentication in the system are derived from a
single **master key**, similar to the model used in cryptographic
wallets.

There are:
- no phone numbers
- no email addresses
- no usernames chosen arbitrarily
- no login/password authentication

An account is a cryptographic identity, not a record in a database.

Loss of the master key implies loss of the account.
There is no account recovery by design.
## End-to-End Encryption

All user data is protected with guaranteed end-to-end encryption.

- Messages are encrypted on the client
- Only intended recipients can decrypt the content
- The server never has access to plaintext messages
- Encryption keys never leave the client

The server operates solely on encrypted data.
## Server Role

Servers are centralized but intentionally **untrusted**.

The server acts as a dumb store responsible only for:
- storing encrypted payloads
- storing public keys
- routing encrypted messages

The server:
- cannot read messages
- cannot impersonate users
- cannot forge identities
- cannot decrypt stored data

Compromise of the server does not compromise message confidentiality.
## Metadata Minimization

The system is designed to avoid collection of unnecessary metadata.

The server does not:
- track social graphs
- analyze communication patterns
- link identities to real-world identifiers

Any metadata required for operation is minimized by design and
treated as a potential attack surface.
## Verifiable Identity and Key Authenticity

Usernames are not arbitrary identifiers.

They are deterministically derived from cryptographic material using
a verifiable scheme. This allows users to independently verify that
a public key truly belongs to the intended peer.

This design prevents:
- silent key substitution
- server-side impersonation
- man-in-the-middle attacks during key distribution

Trust in a peer is established through cryptographic verification,
not server assertions.
## Transparency and Simplicity

The entire system is implemented in **pure C**:
- cryptography
- binary protocols
- client core
- server implementation

This choice is intentional and driven by the following goals:
- maximal transparency
- minimal abstraction layers
- predictable performance
- precise control over memory and execution

The codebase favors explicitness over convenience.
## Performance as a Design Constraint

High performance is not an afterthought.

The system is designed with:
- low-level binary protocols
- minimal runtime overhead
- deterministic behavior

Performance considerations must not weaken security guarantees,
but inefficiency is treated as a form of technical debt.
## Design Trade-offs

This philosophy intentionally accepts certain trade-offs:

- usability is secondary to security
- key loss is irreversible
- centralized servers are used, but never trusted
- complexity is pushed to the client, not the infrastructure

These trade-offs are considered acceptable and necessary to uphold
the system’s security model.
## Guiding Principle

> If a security property cannot be enforced cryptographically,
> it is not considered a security property.

This principle guides all architectural, cryptographic,
and protocol-level decisions in the project.
