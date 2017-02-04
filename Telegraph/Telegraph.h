#ifndef __TELEGRAPH_H__
#define __TELEGRAPH_H__

class Telegraph {
    public:
        Telegraph(const int dit_len);
        void send_message(const char* message);

    private:
        void dit();
        void dah();
        void output_code(const char* code);
        void output_symbol(const int length);

        int dit_length;
        int dah_length;
};

#endif // __TELEGRAPH_H__

