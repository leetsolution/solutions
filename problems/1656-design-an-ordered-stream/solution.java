import java.util.ArrayList;
import java.util.List;

class OrderedStream {

    private String[] stream;
    private int ptr;
    private int n;

    public OrderedStream(int n) {
        this.stream = new String[n + 1];
        this.ptr = 1;
        this.n = n;
    }

    public List<String> insert(int idKey, String value) {
        stream[idKey] = value;
        List<String> result = new ArrayList<>();
        while (ptr <= n && stream[ptr] != null) {
            result.add(stream[ptr]);
            ptr++;
        }
        return result;
    }
}