Key Abstractions 

1. File (big string of bytes)

2. file name

3. Folders, containers for other directories - Tree


I would represent the directories of the file system as a tree, with each node having an array of File objects. If the File is a file, it honly has a data attribute, as well as a timestamp, etc. If it is a folder, it has no data attribute, and a list of pointers to other file objects. The metadata included with the file has its name, extension, time created, etc. 


class File {

    //metadata[0] is the name, metadata[1] is the extension, 2 is date created, etc. 
    string *metadata;

    byte *data;
    File **children;

    public File(byte *data) {
        this->data = data;
    }


    public File(File **children) {
        this->children = children;
    }
}

