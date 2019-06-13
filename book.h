class book{
    private:
        int bId;
        string bName;
        string bAuthor;

    public:
        book(int id,string name,string author);
        ~book();
        void setId(int id);
        void setName(string name);
        void setAuthor(string author);
        int getId();
        string getName();
        string getAuthor();
};
