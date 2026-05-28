class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result;

        for (const auto& s : strs) {
            result += to_string(s.size()) + '#' + s;
        }

        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        string_view sv = s;
        size_t i = 0;

        while (i < s.size()) {
            size_t delimPos = sv.find('#', i);
            if (delimPos == string_view::npos) {
                break;
            }

            int len;
            from_chars(sv.data() + i, sv.data() + delimPos, len);

            i = delimPos + 1;
            result.emplace_back(sv.substr(i, len));
            i += len;
        }

        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

