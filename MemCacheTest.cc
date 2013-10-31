#include "MemCache.h"
#include<iostream>
using namespace memcache;

int main()
{
	MemCache cache;
	cache.set("fuck", strlen("fuck"), "abcde", strlen("abcde"), 100);
	ValuePtr fuck = cache.get("fuck", strlen("fuck"));
	std::cout<<fuck.get()<<std::endl;
}
