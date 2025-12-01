п»ї// Task_2(proxy).cpp 

#include <map>
#include <string>
#include <iostream>

class VeryHeavyDatabase {
public:
     std::string GetData(const std::string& key) const noexcept {
        return "Very Big Data String: \t" + key +"\t <<<" __FUNCTION__+">>>";
    }
};

class CacheProxyDB : VeryHeavyDatabase {
public:
    explicit CacheProxyDB(VeryHeavyDatabase* real_object) : real_db_(real_object) {}

    std::string GetData(const std::string& key) noexcept {
        if (cache_.find(key) == cache_.end()) {
            std::cout << "Get from real object\n";
            cache_[key] = real_db_->GetData(key);
        }
        else {
            std::cout << "Get from cache\n";
        }
        return cache_.at(key);
    }

private:
    std::map<std::string, std::string> cache_;
    VeryHeavyDatabase* real_db_;
};

class TestDB : VeryHeavyDatabase {
public:
    explicit TestDB(VeryHeavyDatabase* real_object) : real_db_(real_object) {}

    std::string GetData(const std::string& key) noexcept {

         return "test_data";
    }

private:
    VeryHeavyDatabase* real_db_;
 };


class TestDB1 : VeryHeavyDatabase {
public:
    explicit TestDB1(VeryHeavyDatabase* real_object) : real_db_(real_object) {}

    std::string GetData(const std::string& key, const std::string& tt) noexcept {

        ta = real_db_->GetData(key);
        
        return (ta+tt);
    }
private:
    std::string ta;
    VeryHeavyDatabase* real_db_;    
};

class OneShotDB : VeryHeavyDatabase {
public:
    explicit OneShotDB(VeryHeavyDatabase* real_object, size_t shots = 1) : real_db_(real_object), shots_(shots) {}

    std::string GetData(const std::string& key) noexcept {

        if (count_ < shots_) {
            ta_ = real_db_->GetData(key);
        }
        else {
            ta_ = real_db_->GetData("<<< Error >>>");
        }
        ++count_;
        return  ta_;
    }

private:
    std::string ta_;
    int shots_, count_{ 0 };
    VeryHeavyDatabase* real_db_;
};


int main() {
    VeryHeavyDatabase real_db = VeryHeavyDatabase();
    VeryHeavyDatabase* ptr = std::addressof(real_db);

    CacheProxyDB cached_db = CacheProxyDB(ptr);
    TestDB1 test_db1 = TestDB1(ptr);
    TestDB test_db = TestDB(ptr);

    std::cout << cached_db.GetData("key") << std::endl;
    std::cout << cached_db.GetData("key") << std::endl;
    std::cout << test_db1.GetData("key!!!", " <-exemple-> ") << std::endl;
    std::cout << test_db.GetData("key") << std::endl;

    std::cout << std::endl;
    std::cout << "<<--------------Task 2----------------->>" << std::endl;
    auto limit_db = OneShotDB(ptr, 2);
    std::cout << limit_db.GetData("< key 1 !!! >") << std::endl;
    std::cout << limit_db.GetData("< key 2 !!! >") << std::endl;
    std::cout << limit_db.GetData("< key 3 !!! >") << std::endl;
    
 /*
Output:
        >> > value
        >> > value
        >> > error
        ```

        ------
*/

    return 0;
}
