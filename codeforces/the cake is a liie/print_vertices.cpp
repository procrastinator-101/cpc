k = n;
while (k--)
{
	for (auto s : vertices[k])
		std::cout << s;
	std::cout << std::endl;
}
std::cout << "\npieces\n\n";
while (++k < n)
{
	for (auto s : pieces[k])
		std::cout << s;
	std::cout << std::endl;
}
