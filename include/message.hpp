

struct tcp_message_header
{
    long version;
    char magic_num[5];
    size_t message_len;
    char reserved;
};
struct tcp_message
{
    tcp_message_header header;
    char* buf;

    tcp_message()
    {
        header.version = 1;
        header.magic_num = {'M', 'a', 'g', 'i', 'c'};
        header.message_len = 0;
        header.reserved = 0;
        buf = NULL;
    }
    ~tcp_message()
    {

    }
    bool is_valid()
    {
        string tmp_str(&header.magic_num, 5);

        return (tmp_str=="Magic");
    }

    size_t get_len()
    {
        return (header.message_len + sizeof(tcp_message_header));
    }


    char* get_payload()
    {
        return buf;
    }
    bool form_msg(char* buff, size_t len)
    {
        header.message_len = len;
        header.buf = buf;
        return true;
    }

};
    tcp_message* append_msg(tcp_message* msg, char* buf, size_t len)
    {
        size_t msg_len = msg->message_len + len + sizeof(tcp_message_header);
        // use realloc later
        char* msg_ptr = malloc(msg_len);
        if(!msg_ptr)
        {
            return NULL;
        }
        if(!memcpy(msg_ptr, msg, msg->message_len + sizeof(tcp_message_header)))
        {
            return NULL;
        }
        if(!memcpy(msg_ptr+len, buf, len))
        {
            return NULL;
        }
        return msg_ptr;
    }
