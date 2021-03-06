#include <iostream>
#include <cassert>
#include "Vector.hpp"

int main() {
    Vector v;
    v.insert(0, 0);
    v.insert(v.size(), 1);
    v.append(2);

    for (int i = 0; i < v.size(); ++i) {
        assert(i == v.get(i));
        assert(i == v[i]);
        v[i] = i+1;
        assert(v.size() == 3);
    } for (int i = 0; i < v.size(); ++i) {
        assert(i+1 == v.get(i));
        assert(i+1 == v[i]);
        assert(v.size() == 3);
    }
    for (int i = 0; i < v.size(); ++i) {
        std::cout << "v[" << i << "]: " << v[i] << std::endl;
    }
    v.remove(0);
    for (int i = 0; i < v.size(); ++i) {
        std::cout << "v[" << i << "]: " << v[i] << std::endl;
    }
    assert(v[0] == 2);
    assert(v[1] == 3);
	
    try {
        v.remove(-1);
    } catch (char const* c) {
        std::cout << c << std::endl;
        assert(true); 
    } catch (...) {
        assert(false);
    }
	
    v.remove(0);
    assert(v.size() == 1);
    v.remove(0);
	
    assert(v.size() == 0);

    try {
        v.remove(0);
    } catch (char const* c) {
        std::cout << c << std::endl;
        assert(true); 
    } catch (...) {
        assert(false);
    }

    v.append(1);

    Vector w(std::move(v));

    assert(v.size() == 0);

    assert(w.size() == 1);

    assert(w[0] == 1);
	
    std::cout << std::endl;
    std::cout << "SUCCESS" << std::endl;
    return 0;
}
