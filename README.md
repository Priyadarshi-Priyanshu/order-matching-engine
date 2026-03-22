Project name: Order Matching Engine
Tagline: A high-performance Limit Order Book engine built in C++17, 
inspired by HFT system design

What it is:
A from-scratch implementation of a Limit Order Book matching engine 
with price-time priority, a REST + WebSocket API, and a live React dashboard.
Built as a structured learning project covering core HFT engineering concepts.

Tech stack:
- C++17 with CMake and Ninja build system
- vcpkg for dependency management  
- Google Test for unit testing
- Crow for HTTP/WebSocket server
- React + Vite + Tailwind CSS for frontend
- WSL2 Ubuntu 22.04 development environment

Features to list:
- Limit Order Book with bids and asks sorted by price-time priority
- Matching engine supporting Market, Limit, IOC, and FOK order types
- Partial fill handling
- Market data feed simulator generating realistic order streams
- REST API: GET /orderbook, POST /order, DELETE /order/:id, GET /trades
- WebSocket endpoint for live book updates
- React dashboard with live LOB display, order form, trade tape, price chart
- Performance benchmarks with memory pool optimisation

Architecture overview section:
Show the folder structure like this:
order-matching-engine/
├── src/
│   ├── core/        # Order, PriceLevel, OrderBook
│   ├── matching/    # MatchingEngine, Trade events  
│   ├── feed/        # FeedHandler, FeedSimulator
│   └── api/         # HTTP server, REST routes
├── include/         # Header files mirroring src/
├── tests/           # Google Test unit tests
├── frontend/        # React dashboard
└── CMakeLists.txt

Build instructions section:
Prerequisites: WSL2 Ubuntu 22.04, cmake 3.22+, gcc 11+, vcpkg, Node.js 18+
Commands:
git clone <repo>
cd order-matching-engine
cmake -B build -G Ninja
cmake --build build
./build/lob_engine

Run tests:
cd build && ctest --output-on-failure

Run frontend:
cd frontend && npm install && npm run dev

Status badges to include at top:
- Build: passing
- Tests: passing  
- Language: C++17
- License: MIT

Style: Professional, clean, no fluff. 
Use proper markdown with headers, code blocks, and a table for the API endpoints.
Add a "Key engineering decisions" section explaining:
1. int64_t for prices (no float)
2. std::map for price levels (sorted, O(log n))
3. Price-time priority matching
4. Separation of matching engine from API layer
