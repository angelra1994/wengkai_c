#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

class Student
{
public:
    int id;
    std::string name;

    // 构造函数
    Student(int id, const std::string &name) : id(id), name(name) {}

    // 成员函数，用于打印姓名
    void printName() const
    {
        std::cout << name << std::endl;
    }
};

// 从文件中读取学生信息
std::vector<Student> readStudentsFromFile(const std::string &filename)
{
    std::vector<Student> students;
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "无法打开文件：" << filename << std::endl;
        return students;
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string idStr, name;
        if (std::getline(iss, idStr, ',') && std::getline(iss, name))
        {
            try
            {
                int id = std::stoi(idStr);
                students.emplace_back(Student(id, name));
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << "无效的学号：[" << idStr << "], 在文件: " << filename << std::endl;
            }
            catch (const std::out_of_range &e)
            {
                std::cerr << "学号超出范围：[" << idStr << "], 在文件: " << filename << std::endl;
            }
        }
        else
        {
            std::cerr << "内容格式错误在: [" << line << "], 在文件：" << filename << std::endl;
        }
    }
    file.close();
    return students;
}

/**
 * 根据学号查找学生姓名
 */
const Student* findStudent(const std::vector<Student> &students, int id)
{
    // 此处是引用拷贝，不需要复制出来一个student对象
    for (auto &student : students)
    {
        if (student.id == id)
        {
            return &student;
        }
        // 声明变量的时候，&是引用。
    }
    return nullptr;
}


int main(int argc, char const *argv[])
{
    std::vector<Student> students = readStudentsFromFile("students.txt");
    int id;
    while (true)
    {
        std::cout << "请输入学号（输入-1退出）：";
        std::cin >> id;
        if (id == -1) {
            break;
        }
        const Student* student = findStudent(students, id);
        if(student) {
            student -> printName();
        } else {
            std::cout << "未找见与学号：[" << id << "] 对应的学生" << std::endl;
        } 
    }
    
    return 0;
}
