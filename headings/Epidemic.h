struct Epidemic {
    Virus virus;
    double total_infected;
    double total_dead;
    double total_recovered;

    Epidemic(const Virus& v) : virus(v), total_infected(1.0), total_dead(0.0), total_recovered(0.0) {}
};
