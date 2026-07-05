import java.util.ArrayList;

public class Generic_List<T> {
    private ArrayList<T> list = new ArrayList<T>();

    public ArrayList<T> getList() {
        return list;
    }

    public void setList(ArrayList<T> list) {
        this.list = list;
    }

    public void addItem(T item){
        list.add(item);
    }

    public T getItem(int index)
    {
        return list.get(index);
    }
}
