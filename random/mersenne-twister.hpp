#pragma region mersenne_twister

#ifndef MERSENNE_TWISTER_HPP
#define MERSENNE_TWISTER_HPP

namespace rng {
	mt19937 mst(chrono::steady_clock::now().time_since_epoch().count());
}

#endif

#pragma endregion mersenne_twister