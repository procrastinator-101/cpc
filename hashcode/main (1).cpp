#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <map>
#include <algorithm>
#include <climits>


#define FILE_NUMBER 1
#define OUTPUT_FILE "outputfile.txt"

int         currentDay;

enum ProjectState {
    start,
    onGoing,
    finish
};

enum ContributorsState {
    not_occupied,
    occupied
};

struct Contributor {
    std::string name;
    std::vector<std::pair<std::string, int> > skills;
    ContributorsState state;
    Contributor(const std::string & name) {
        this->name = name;
        state = not_occupied;
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
    int            endDay;
    std::vector<Contributor *> pc;
    ProjectState   state;
    std::vector<std::pair<std::string, int> > required_skills;
    Project(const std::string & name, int duration, int score, int best_before, int number_of_contributors)
    {
        this->name = name;
        this->duration = duration;
        this->score = score;
        this->best_before = best_before;
        this->Ncontributors = number_of_contributors;
        state = start;
        endDay = -1;
    }
    void    addRequiredSkills(const std::string & skill_name, int skill_level) {
        this->required_skills.push_back(std::make_pair(skill_name, skill_level));
    }
};


void    AssignedProject(Project & project, std::vector<Contributor> & conts, int currentDay)
{
    for (std::pair<std::string, int> rskill: project.required_skills)
    {
        Contributor *bestMatch = nullptr;
        int         level = 100000;
        for (Contributor & c : conts)
        {
            if (c.state == occupied)
                continue;
            for (std::pair<std::string, int> skill: c.skills)
            {
                
                if (rskill.first == skill.first)
                {
                    if (skill.second == rskill.second)
                    {
                        level = skill.second;
                        bestMatch = &c;
                        break;
                    }
                    if (skill.second < level &&  rskill.second - 1 <= skill.second)
                    {
                        level = skill.second;
                        bestMatch = &c;
                    }
                }
            }
            if (bestMatch)
            {
                bestMatch->state = occupied;
                project.pc.push_back(bestMatch);
                break;
            }
        }
    }
    project.endDay = currentDay + project.duration;
    project.state = onGoing;
}


void        FinishedProject(Project & project)
{
    project.state = finish;
    for (Contributor *c: project.pc)
    {
        c->state = not_occupied;
    }
    project.pc.clear();
}

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


bool    checkProjectRequirement(const Project & project, const std::vector<Contributor> & conts)
{
    int matched = 0;

    for (std::pair<std::string, int> rskill: project.required_skills)
    {
        Contributor *bestMatch = nullptr;
        int         level = 100000;
        for (Contributor  c : conts)
        {
            if (c.state == occupied)
                continue;
            for (std::pair<std::string, int> skill: c.skills)
            {
                
                if (rskill.first == skill.first)
                {
                    if (skill.second == rskill.second)
                    {
                        level = skill.second;
                        bestMatch = &c;
                        break;
                    }
                    if (skill.second < level &&  rskill.second - 1 <= skill.second)
                    {
                        level = skill.second;
                        bestMatch = &c;
                    }
                }
            }
            if (bestMatch)
            {
                matched++;
                break;
            }
        }
    }
    return matched >= project.Ncontributors;
}

int    getBrutValue(Project& p, int currentDay)
{
    return (p.score + (p.best_before - currentDay - p.duration)) * 100;
}

bool	sortFunction(Project* a, Project* b)
{
	return getBrutValue(*a, currentDay) < getBrutValue(*b, currentDay);
}

// FUNCTION ASSIGN PROJECT TO CONTRIBUTORS
int     main(int argc, char **argv)
{
    std::vector<Project> projects;
    std::vector<Contributor>  contributors;
    std::cout << argv[FILE_NUMBER] << std::endl;
    std::ifstream f(argv[FILE_NUMBER]);
    std::vector<Project *>  ChoosenProjects;

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
    std::cout << "ALGO" << std::endl;
    currentDay = 0;
	int incrmentDay = INT_MAX;
	while (1)
	{
		incrmentDay = INT_MAX;
		//finish due on going projetcs
		for (Project & project: projects)
		{
			if (project.state == onGoing && currentDay >= project.endDay)
			{
				FinishedProject(project);
			}
		}
		std::cout << "chose projects" << std::endl;
		//chose projects
		for (Project & project: projects)
		{
			if (project.state == finish)
				continue;
			if (project.state == start)
			{
				if (checkProjectRequirement(project, contributors))
				{
					ChoosenProjects.push_back(&project);
					if (incrmentDay > project.duration)
						incrmentDay = project.duration;
				}
			}
		}
		std::cout << "here" << std::endl;
		if (!ChoosenProjects.size())
			break;
		sort(ChoosenProjects.begin(), ChoosenProjects.end(), sortFunction);
		//execute projects
		for (int i = 0; i < ChoosenProjects.size(); i++)
		{
			if (checkProjectRequirement(*ChoosenProjects[i], contributors))
				AssignedProject(*ChoosenProjects[i], contributors, currentDay);
		}
		currentDay += incrmentDay;
	}
    return (0);
}