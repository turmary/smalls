// multiple thread to calc primes
//   arg1 number start
//   arg2 number count

// compiling command line
//   g++ -o prime-thread -DUSING_THREAD=0 prime-thread.cc -lpthread
//   # or
//   g++ -o prime-thread -DUSING_THREAD=1 -Wl,-\( -lpthread prime-thread.cc -Wl,-\)

#ifndef USING_THREAD
#define USING_THREAD 1
#endif

#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cmath>
#include <cinttypes>
#include <set>
#include <deque>
#include <iostream>
using namespace std;

#if USING_THREAD
#include <vector>
#include <thread>
#include <mutex>
#include <functional>

#define USING_MUX 1
#endif

uint64_t start;
uint64_t range;
deque<uint64_t> primes;
deque<uint64_t> potentials;
#if USING_THREAD
#if USING_MUX
mutex poten_mtx;
mutex prime_mtx;
  #define LOCK(mx) mx.lock()
  #define UNLOCK(mx) mx.unlock()
#else
  #define LOCK(mx)
  #define UNLOCK(mx)
#endif
#endif

bool is_prime(uint64_t x) {
	uint64_t root;

	// if (x < 2)
	//	return false;

	root = sqrt(x);
	for (uint64_t i = 2; i <= root; i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

#if USING_THREAD
int task_prime(deque<uint64_t>& q) {
	uint64_t v;

	for (;;){
		LOCK(poten_mtx);

		if (q.empty()) {
			UNLOCK(poten_mtx);
			break;
		}

		v = q.front();
		q.pop_front();
		UNLOCK(poten_mtx);

		if (is_prime(v)) {
			LOCK(prime_mtx);
			primes.push_back(v);
			UNLOCK(prime_mtx);
		}
	}
	return 0;
}
#endif

int main(int argc, const char* argv[]) {
	start = 100000000;
	if (argc > 1) {
		start = atoll(argv[1]);
	}
	range =  10000000;
	if (argc > 2) {
		range = atoll(argv[2]);
	}
	printf("x in [%" PRIu64 ", %" PRIu64 ")\n",
	              start,       start + range);

	for (uint64_t i = start; i < start + range; i++) {
		// cout <<"root = " <<(uint64_t)sqrt(i) <<endl;
		#if USING_THREAD
		potentials.push_back(i);
		#else
		if (is_prime(i)) {
			primes.push_back(i);
			// cout <<i <<endl;
		}
		#endif
	}

	#if USING_THREAD
	const int cpus = 4;
	vector<thread> threads;
	for (int c = 0; c < cpus; c++) {
		threads.push_back(thread(task_prime, ref(potentials)));
	}
	for (auto& th: threads) th.join();
	#endif

	/*
	for (auto& p: primes) {
		cout <<p <<endl;
	}
	*/
	cout <<primes.size() <<endl;
	return 0;
}

