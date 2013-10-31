#include <boost/noncopyable.hpp>

#include <string>
#include <memory>

#include <libmemcached/memcached.h>
namespace memcache
{
using std::string;

typedef std::unique_ptr<char> ValuePtr;

class MemCache : boost::noncopyable
{
public:
	explicit MemCache();
	explicit MemCache(const string& ip, uint16_t port);
	void init(const string& ip, uint16_t port);
	ValuePtr get(const char *key, size_t key_length);	
	void set(const char* key, size_t key_length, const char *value,
			size_t value_length, time_t expiration);
private:
	std::unique_ptr<memcached_st> st_;
};

}
