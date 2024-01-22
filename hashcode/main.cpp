#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <fstream>

#define FILE_NUMBER 1
#define OUTPUT_FILE "outputfile.txt"

struct Contributor {
    std::string name;
    std::vector<std::pair<std::string, int> > skills;
    Contributor(const std::string & name) {
        this->name = name;
    }
    void addSkill(const std::string & skill_name, int skill_level)
    {
        this->skills.push_back(std::make_pair(skill_name, skill_level));
    }
};

struct Project {
    std::string    name;
    int            duration;
    int            score;
    int            best_before;
    int            Ncontributors;
    std::vector<std::pair<std::string, int> > required_skills;
    Project(const std::string & name, int duration, int score, int best_before, int number_of_contributors)
    {
        this->name = name;
        this->duration = duration;
        this->score = score;
        this->best_before = best_before;
        this->Ncontributors = number_of_contributors;
    }

    void    addRequiredSkills(const std::string & skill_name, int skill_level) {
        this->required_skills.push_back(std::make_pair(skill_name, skill_level));
    }
};

std::ostream & operator<<(std::ostream & os, const Project & project)
{
    os << project.name << " " << project.duration << " " << project.score << " " << project.best_before << " " << project.Ncontributors << std::endl;
    os << "SKILLS REQUIRED:\n";
    for (std::pair<std::string, int> p: project.required_skills)
    {
        os << p.first << " " << p.second << std::endl;
    }
    return (os);
}

int	getBrutValue(Project& p, int currentDay)
{
	return (p.score + (p.best_before - currentDay - p.duration)) * 100;
}

int getAddedValue(Project& p, )

std::ostream & operator<<(std::ostream & os, const Contributor & c)
{
    os << c.name << std::endl;
    os << "SKILLS:\n";
    for (std::pair<std::string, int> p: c.skills)
    {
        std::cout << p.first << " " << p.second << std::endl;
    }
    return (os);
}

int     main(int argc, char **argv)
{
    std::vector<Project> projects;
    std::vector<Contributor>  contributors;
    std::cout << argv[FILE_NUMBER] << std::endl;
    std::ifstream f(argv[FILE_NUMBER]);
    int     numberOfContibutors;
    int     numberOfProjects;
    std::string name;
    int         skillsCount;
    std::string skill_name;
    int         skill_level;
    int         project_duration;
    int         project_score;
    int         project_best_before; // if you finish the project you gonna have the full score
    int         project_roles; // contributors
    f >> numberOfContibutors >> numberOfProjects;
    while (--numberOfContibutors >= 0)
    {
        f >> name >> skillsCount;
        Contributor c(name);
        while (--skillsCount >= 0)
        {
            f >> skill_name >> skill_level;
            c.addSkill(skill_name, skill_level);
        }
        contributors.push_back(c);
    }
    while (--numberOfProjects >= 0)
    {
        f >> name >> project_duration >> project_score >> project_best_before >> project_roles;
        Project p(name, project_duration, project_score, project_best_before, project_roles);
        while (--project_roles >= 0)
        {
            f >> skill_name >> skill_level;
            p.addRequiredSkills(skill_name, skill_level);
        }
        projects.push_back(p);
    }
    std::cout << "Contributors:" << std::endl;
    for (Contributor c: contributors)
    {
        std::cout << c << std::endl;
    }
    std::cout << "Projects: " << std::endl;
    for (Project p: projects)
    {
        std::cout << p << std::endl;
    }
    return (0);
}
