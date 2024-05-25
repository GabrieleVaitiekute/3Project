# 3Project

## 1 TESTAVIMO APRAŠYMAS

 Išplėčiau  Vector klases funkcionalumą taip, kad ji būtų pilnavertė alternatyvą std::vector konteineriui. Patikrinimui funkcionalumą (Member types, Member functions, Non-member functions) naudojausi https://en.cppreference.com/w/cpp/container/vector. Apačioje pateikti kodų pavyzdžiai bei nuotraukos su tikėtinais (baltame fone) ir gautais (juodame fone) outputais.

   1.1 Operator= 
   
        void print(auto const comment, auto const& container)
      {
        auto size = std::size(container);
        std::cout << comment << "{ ";
        for (auto const& element : container)
            std::cout << element << (--size ? ", " : " ");
        std::cout << "}\n";
      }
     
    int main()
      {
        std::vector<int> x{1, 2, 3}, y, z;
        const auto w = {4, 5, 6, 7};
     
        std::cout << "Initially:\n";
        print("x = ", x);
        print("y = ", y);
        print("z = ", z);
     
        std::cout << "Copy assignment copies data from x to y:\n";
        y = x;
        print("x = ", x);
        print("y = ", y);
     
        std::cout << "Move assignment moves data from x to z, modifying both x and z:\n";
        z = std::move(x);
        print("x = ", x);
        print("z = ", z);
     
        std::cout << "Assignment of initializer_list w to z:\n";
        z = w;
        print("w = ", w);
        print("z = ", z);
      }
  
<img src="https://github.com/GabrieleVaitiekute/3Project/assets/147078486/bb710f31-9804-4bf7-935b-9aa9ef331cb6" width="500">


  1.2 Capacity

        std::vector<int> v;
        std::cout << "Default-constructed capacity is " << v.capacity() << '\n';
        v.resize(100);
        std::cout << "Capacity of a 100-element vector is " << v.capacity() << '\n';
        v.resize(50);
        std::cout << "Capacity after resize(50) is " << v.capacity() << '\n';
        v.shrink_to_fit();
        std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';
        v.clear();
        std::cout << "Capacity after clear() is " << v.capacity() << '\n';
        v.shrink_to_fit();
        std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';
        for (int i = 1000; i < 1300; ++i)
            v.push_back(i);
        std::cout << "Capacity after adding 300 elements is " << v.capacity() << '\n';
        v.shrink_to_fit();
        std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';



<img src="https://github.com/GabrieleVaitiekute/3Project/assets/147078486/e354587b-8f47-41e5-b46e-48adf4743b25" width="500">


  1.3 Insert

      void print(int id, const std::vector<int>& container)
      {
          std::cout << id << ". ";
          for (const int x : container)
              std::cout << x << ' ';
          std::cout << '\n';
      }
       
      int main ()
      {
          std::vector<int> c1(3, 100);
          print(1, c1);
       
          auto it = c1.begin();
          it = c1.insert(it, 200);
          print(2, c1);
       
          c1.insert(it, 2, 300);
          print(3, c1);
       
          // `it` no longer valid, get a new one:
          it = c1.begin();
       
          std::vector<int> c2(2, 400);
          c1.insert(std::next(it, 2), c2.begin(), c2.end());
          print(4, c1);
       
          int arr[] = {501, 502, 503};
          c1.insert(c1.begin(), arr, arr + std::size(arr));
          print(5, c1);
       
          c1.insert(c1.end(), {601, 602, 603});
          print(6, c1);
        }
 
<img src="https://github.com/GabrieleVaitiekute/3Project/assets/147078486/90355d88-107f-4f62-bae4-eeb0dd5f3e7b" width="500">


  1.4 Erase

        void print_container(const std::vector<int>& c)
      {
        for (int i : c)
            std::cout << i << ' ';
        std::cout << '\n';
      }
    
    int main()
      {
        std::vector<int> c{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        print_container(c);
    
        c.erase(c.begin());
        print_container(c);
    
        c.erase(c.begin() + 2, c.begin() + 5);
        print_container(c);
    
        // Erase all even numbers
        for (std::vector<int>::iterator it = c.begin(); it != c.end();)
        {
            if (*it % 2 == 0)
                it = c.erase(it);
            else
                ++it;
        }
        print_container(c);
      }

<img src="https://github.com/GabrieleVaitiekute/3Project/assets/147078486/310aa22f-9c9f-4cdf-843a-7157e98de926" width="500">


  1.5 Push_back

       std::vector<std::string> letters;
    
     letters.push_back("abc");
     std::string s{ "def" };
     letters.push_back(std::move(s));
    
     std::cout << "std::vector letters holds: ";
     for (auto&& e : letters)
         std::cout << std::quoted(e) << ' ';
    
     std::cout << "\nMoved-from string s holds: " << std::quoted(s) << '\n';

<img src="https://github.com/GabrieleVaitiekute/3Project/assets/147078486/a5f62e14-af86-4f27-a1c7-1e7e500b2cc0" width="500">


  1.6 Resize

        void print(auto rem, const std::vector<int>& c)
    {
        for (std::cout << rem; const int el : c)
            std::cout << el << ' ';
        std::cout << '\n';
    }
    
    int main()
    {
        std::vector<int> c = { 1, 2, 3 };
        print("The vector holds: ", c);
    
        c.resize(5);
        print("After resize up to 5: ", c);
    
        c.resize(2);
        print("After resize down to 2: ", c);
    
        c.resize(6, 4);
        print("After resize up to 6 (initializer = 4): ", c);
    }

<img src="https://github.com/GabrieleVaitiekute/3Project/assets/147078486/30935edb-c4fd-4510-b1c9-513e41cc90d2" width="500">


## 2 EFEKTYVUMO/SPARTOS ANALIZĖ NAUDOJANT PUSH_BACK()


## 3 ATMINTIES PERSKIRTYMAI


## 4 VECTOR VEIKLOS PALYGINIMAS SU STD::VECTOR
  1. Spartos analizė
  2. Catch testai
     Testavimą atlikau su Catch2. Testai: Default konstruktorius, Parametrizuotas konstruktorius, Copy konstruktorius, Move konstruktorius, Copy priskyrimo operatorius, Move priskyrimo operatorius, Ivesties operatorius, Isvesties operatorius, Push back, size, Capacity, Modifiers, Relational Operators.

  4. Doxygen
  5. Setup.exe 

