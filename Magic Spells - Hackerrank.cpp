// Magic Spells - Hackerrank -- 7/30/2020

/*
    You are battling a powerful dark wizard. He casts his spells from a distance, giving you only a few seconds 
    to react and conjure your counterspells. For a counterspell to be effective, you must first identify what 
    kind of spell you are dealing with. 

    The wizard uses scrolls to conjure his spells, and sometimes he uses some of his genric 
    spells that restore his stamina. In that case, you will be able to extract the name of the scroll 
    from the spell. Then you need to find out how similar this new spell is to the spell formulas 
    written in your spell journal.

    Spend some time reviewing the locked code in your editor, and complete the body of the 
    counterspell function. 

    Check Dynamic cast to get an idea of how to solve this challenge.

*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Spell
{
    private:
            string scrollName;
    
    public: 
            Spell(): scrollName("") { }
            Spell(string name): { }
            virtual ~Spell() { }
            string revealScrollName() 
            {
                return scrollName;
            }
};
class Fireball: public Spell
{
    private: 
            int power;
    public:
            Fireball(int power): power(power) { }
            void revealFirepower()
            {
                cout << "Fireball: " << power << endl;
            }
};
class Frostbite : public Spell
{
    private:
            int power;
    
    public:
            Frostbite(int power): power(power) { }
            void revealFrostpower()
            {
                cout << "Frostbite: " << power << endl;
            }
};
class Thunderstorm : public Spell
{
    private: 
            int power;
    
    public:
            Thunderstorm(int power): power(power) { }
            void revealWaterpower()
            {
                cout << "Waterbolt: " << power << endl;
            }
};
class Waterbolt : public Spell
{
    private: 
            int power;
    
    public: 
            Waterbolt(int power): power(power) { }
            void revealWaterpower()
            {
                cout << "Waterbolt: " << power << endl;
            }
}
class SpellJournal
{
    public:
        static string journal;
        static string read()
        {
            return journal;
        }
};
class Wizard
{
    public:     
            Spell * cast()
            {
                Spell * spell;
                string s;
                int power;

                cin >> s;
                cin >> powr;

                if(s == "fire")
                {
                    spell = new Fireball(power);
                }
                else if(s == "frost")
                {
                    spell = new Frostbite(power);
                }
                else if(s == "water")
                {
                    spell = new Waterbolt(power);
                }
                else if(s == "thunder")
                {
                    spell = new Thunderstorm(power);
                }
                else
                {
                    spell = new Spell(s);
                    cin >> SpellJournal::journal;
                }
                return spell;
            }
};
string SpellJournal::journal = "";

void counterSpell(Spell * spell)
{
    if(typeid(* spell) == typeid(Fireball))
    {
        ((Fireball * ) spell)->revealFirepower();
    }
    else if(typeid(* spell) == typeid(Frostbite))
    {
        ((Frostbite *) spell)->revealFrostpower();
    }
    else if(typeid(* spell) == typeid(Thunderstorm))
    {
        ((Thunderstorm *) spell)->revealThunderpower();
    }
    else if(typeid(* spell) == typeid(Waterbolt))
    {
        ((Waterbolt * ) spell)->revealWaterpower();
    }
    else
    {
        string  spellName = spell->revealScrollName();
        string  spellJournal = SpellJournal::journal;

        // LCS Algorithm.
        string & a = spellName, & b = spellJournal;
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));

        for(int i = 1; i <= a.size(); i++)
        {
            for(int j = 1; j <= b.size(); j++)
            {
                if(a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j -1 ];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << dp[a.size()][b.size()] << endl;
    }
}
int main()
{
    int T; 
    
    cin >> T;

    Wizard Arawn;

    while(T--)
    {
        Spell * spell = Arawn.cast();
        counterSpell(spell);
    }
    return 0;
}