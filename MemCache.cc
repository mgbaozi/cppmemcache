#include "MemCache.h"
#include <boost/implicit_cast.hpp>
using namespace boost;
using namespace memcache;

MemCache::MemCache()
		:st_(memcached_create(NULL))
{
	init("localhost", 11211);
}

MemCache::MemCache(const string& ip, uint16_t port)
	:st_(memcached_create(NULL))
{
	init(ip, port);
}

void MemCache::init(const string& ip, uint16_t port)
{
	memcached_return rc;
	memcached_server_st *servers;
	servers = memcached_server_list_append(NULL, ip.c_str(), port, &rc);
	rc = memcached_server_push(st_.get(), servers);
}

ValuePtr MemCache::get(const char *key, size_t key_length)
{
	size_t value_length;
	uint32_t flags;
	memcached_return_t error;
	char *value = memcached_get(st_.get(), key, key_length, &value_length, &flags, &error);
	if(error)
	{
		//TODO:error process
	}
	return ValuePtr(value);
}

void MemCache::set(const char* key, size_t key_length, const char *value,
		size_t value_length, time_t expiration)
{
	memcached_set(st_.get(), key, key_length, value, value_length, expiration, implicit_cast<uint32_t>(0));
}
