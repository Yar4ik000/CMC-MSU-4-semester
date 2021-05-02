#include <iostream>

namespace numbers {

    class complex_stack {
    private:
        size_t count;
        complex *head;
        size_t len;

    public:
        complex_stack() : count{0}, len{10} {
            head = new complex[10];
        }

        complex_stack(const complex_stack& copy) : count{copy.get_count()}, len{copy.get_len()} {
            head = new complex[len];
            for (size_t i = 0; i < count; ++i) {
                head[i] += copy[i];
            }
        }

        ~complex_stack() {
            delete[] head;
        }

        size_t size() const {
            return count;
        }

        complex operator[] (size_t index) const {
            return head[index];
        }

        size_t get_count() const {
            return count;
        }

        size_t get_len() const {
            return len;
        }

        void inc_count() {
            ++count;
        }

        void dec_count() {
            --count;
        }

        complex *get_head() const {
            return head;
        }

        void increase_len() {
            complex *new_head = new complex[len * 2];
            for (size_t i = 0; i < count; ++i) {
                new_head[i] += head[i];
            }
            delete[] head;
            head = new_head;
            len *= 2;
        }

        complex_stack& operator= (complex_stack other) {
            delete[] head;
            head = new complex[other.get_len()];
            len = other.get_len();
            count = other.get_count();
            for (size_t i = 0; i < count; ++i) {
                head[i] += other[i];
            }
            return *this;
        } 
    

        friend complex operator+ (const complex_stack& stack){
            return stack[stack.get_count() - 1];
        }

        friend complex_stack operator~ (const complex_stack& stack){
            complex_stack new_stack = stack;
            new_stack.dec_count();
            return new_stack;
        }
    };

    inline complex_stack operator<< (complex_stack stack, complex number) {
        if (stack.get_count() == stack.get_len()) {
            stack.increase_len();
        }
        stack.get_head()[stack.get_count()] += number;
        stack.inc_count();
        return stack;
    }
}
