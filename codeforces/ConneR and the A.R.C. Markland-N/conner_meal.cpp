/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conner_meal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 00:17:15 by youness           #+#    #+#             */
/*   Updated: 2020/04/15 01:37:34 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream> 
#include<algorithm>
#include <set>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, s, k, i, a;
		set <int> floors;
		cin >> n >> s >> k;
		i = k;
		while (i--)
		{
			cin >> a;
			floors.insert(a);
		}
		i = -1;
		while (++i <= k)
		{
			if (s - i >= 1 && floors.find(s - i) == floors.end())
			{
				cout << i << endl;
				break ;
			}
			if (s + i <= n && floors.find(s + i) == floors.end())
            {
                cout << i << endl;
                break ;
            }
		}
	}
	return (0);
}
