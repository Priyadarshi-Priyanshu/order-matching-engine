# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a C++ order matching engine project, currently in early/scaffolding stage. The only source file so far is `hello.cpp`.

## Build & Run

```bash
# Compile
g++ -o order_engine <source_file.cpp>

# Run
./order_engine
```

No build system (CMake, Makefile, etc.) has been set up yet. Once one is introduced, update this file accordingly.

## Architecture

No engine logic exists yet. When building the order matching engine, the expected core components are:

- **Order Book**: Maintains buy (bid) and sell (ask) orders, typically using priority queues or sorted maps keyed by price/time.
- **Order types**: Limit, market, and potentially stop orders.
- **Matching logic**: Price-time priority (FIFO) is the standard algorithm — match the best bid against the best ask when they cross.
- **Trade execution**: Emit fills/trades when orders match, handling partial fills.
