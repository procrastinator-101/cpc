#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <map>
#include <algorithm>
#include <climits>


using namespace std;

#define INPUT_FILE 1
#define OUTPUT_FILE 2

int         currentDay;
int	nbExecutedProjects = 0;

enum ProjectState
{
    onHold,
    onGoing,
    finished
};

enum ContributorsState
{
    notOccupied,
    occupied
};

struct Contributor
{
    std::string name;
    std::vector<std::pair<std::string, int> > skills;
    ContributorsState state;
    Contributor(const std::string & name)
	{
        this->name = name;
        state = notOccupied;
    }
    void addSkill(const std::string& skill_name, int skill_level)
    {
        this->skills.push_back(std::make_pair(skill_name, skill_level));
    }

};

struct	

struct Project
{
    int            duration;
    int            score;
    int            bestBefore;
    int            nbContributors;
    int            endDay;
	std::string    name;
    ProjectState   state;

    std::vector<Contributor *> contributers;
    std::vector<std::pair<std::string, int> > required_skills;
    Project(const std::string& name, int duration, int score, int bestBefore, int nbContributors)
    {
        this->name = name;
        this->duration = duration;
        this->score = score;
        this->bestBefore = bestBefore;
        this->nbContributors = nbContributors;
        state = onHold;
    }
    void	addRequiredSkills(const std::string & skill_name, int skill_level)
	{
        this->required_skills.push_back(std::make_pair(skill_name, skill_level));
    }

	void	start(std::vector<Contributor> & conts, int currentDay)
	{
		for (std::pair<std::string, int> rskill : this->required_skills)
		{
			int         level = 12;
			Contributor *bestMatch = nullptr;
			std::pair<std::string, int> *affectedSkill = nullptr;
			for (Contributor & c : conts)
			{
				if (c.state == occupied)
					continue;
				for (std::pair<std::string, int> skill: c.skills)
				{
					
					if (rskill.first == skill.first)
					{
						//mentors need to be checked
						if (skill.second < level &&  rskill.second <= skill.second)
						{
							level = skill.second;
							affectedSkill = &skill;
							bestMatch = &c;
							if (skill.second == rskill.second)
								break;
						}
					}
				}
				if (bestMatch)
				{
					bestMatch->state = occupied;
					this->pc.push_back(bestMatch);
					//update skill level
					affectedSkill->second++;
					break;
				}
			}
		}
		this->endDay = currentDay + this->duration;
		this->state = onGoing;
		nbExecutedProjects++;
	}
	void	finish()
	{
		this->state = finished;
		for (Contributor *c : this->contributers)
			c->state = notOccupied;
	}
};




std::ostream & operator<<(std::ostream & os, const Project & project)
{
    os << project.name << " " << project.duration << " " << project.score << " " << project.bestBefore << " " << project.nbContributors << std::endl;
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
					//no mentorship
                    if (skill.second < level &&  rskill.second <= skill.second)
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
    return matched >= project.nbContributors;
}

int    getBrutValue(Project& p, int currentDay)
{
    return (p.score + (p.bestBefore - currentDay - p.duration)) * 100;
}

bool	sortFunction(Project* a, Project* b)
{
	int score1 = getBrutValue(*a, currentDay);
	int score2 = getBrutValue(*b, currentDay);

	// std::cout << a->name << " " << score1 << std::endl;
	// std::cout << b->name << " " << score2 << std::endl;
	return score1 > score2;
}

// FUNCTION ASSIGN PROJECT TO CONTRIBUTORS
int     main(int argc, char **argv)
{
    std::vector<Project>		projects;
    std::vector<Contributor>	contributors;

	ifstream	input(argv[INPUT_FILE]);
    ofstream	output(argv[OUTPUT_FILE]);

    int     	numberOfContibutors;
    int     	numberOfProjects;

    std::string name;
    int         skillsCount;
    std::string skill_name;
    int         skill_level;
    int         project_duration;
    int         project_score;
    int         project_best_before; // if you finish the project you gonna have the full score
    int         project_roles; // contributors
    
    input >> numberOfContibutors >> numberOfProjects;
    while (--numberOfContibutors >= 0)
    {
        input >> name >> skillsCount;
        Contributor c(name);
        while (--skillsCount >= 0)
        {
            input >> skill_name >> skill_level;
            c.addSkill(skill_name, skill_level);
        }
        contributors.push_back(c);
    }
    while (--numberOfProjects >= 0)
    {
        input >> name >> project_duration >> project_score >> project_best_before >> project_roles;
        Project p(name, project_duration, project_score, project_best_before, project_roles);
        while (--project_roles >= 0)
        {
            input >> skill_name >> skill_level;
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
	int incrmentDay;
	while (1)
	{
		incrmentDay = INT_MAX;
		//finish due on going projetcs
		for (Project & project: projects)
		{
			if (project.state == onGoing && currentDay >= project.endDay)
				project.finish();
		}
		// std::cout << "chose projects" << std::endl;
		std::vector<Project *>  ChoosenProjects;
		for (Project & project: projects)
		{
			if (project.state == finished)
				continue;
			if (project.state == onHold)
			{
				if (checkProjectRequirement(project, contributors))
				{
					ChoosenProjects.push_back(&project);
					if (incrmentDay > project.duration)
						incrmentDay = project.duration;
				}
			}
		}
		if (!ChoosenProjects.size())
			break;
		sort(ChoosenProjects.begin(), ChoosenProjects.end(), sortFunction);
		//execute projects
		for (int i = 0; i < ChoosenProjects.size(); i++)
		{
			if (checkProjectRequirement(*ChoosenProjects[i], contributors))
				AssignedProject(*ChoosenProjects[i], contributors, currentDay);
			for (int i = 0; i < ChoosenProjects.size(); i++)
				std::cout << ChoosenProjects[i]->pc[0] << std::endl;
		}
		currentDay += incrmentDay;
	}
	
    return (0);
}