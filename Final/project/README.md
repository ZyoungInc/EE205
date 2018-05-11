# Soul Quest

# Usage Notes
> Before running the game, scale your terminal window before starting the game.
> This game utilizes the ncurses library. Please install ncurses using
> "sudo apt-get install libncurses-dev" before running the game.
> Since ncurses takes in the size of the window, scaling after the game has
> started will result in the distortion of the interface.
> Run game by typing "make SoulQuest".

# Story
> Through unfortunate circumstances, your beloved wife died in a fire and wish to
> see her once again. In a desperate bid, you sell your soul to a demon for a
> chance of bringing your wife back from the underworld. Halfway through the
> ritual, you blackout and awake in the Demon's dungeon. It was a trick! Now you must
> make your way through the dungeon, confront the demon and reclaim your soul
> (and maybe your wife).

# Game features

## Weapon types
  1. __Lance__  
    *Strong against Sword but weak against Axe. (Warrior class only)*
  2. __Sword__  
    *Strong against Axe but weak against Lance. (Warrior class only)*
  3. __Axe__  
    *Strong against Lance but weak against Sword. (Warrior class only)*
  4. __Staff__
    *Neutral effectiveness (Mage class only)*

## Weapon rarity
  1. __Bronze__  
    *Lowest possible rating.*
  2. __Silver__  
    *Stronger than Bronze but weaker than Gold.*
  3. __Gold__  
    *Stronger than Silver but weaker than Platinum.*
  4. __Platinum__  
    *Stronger than Gold but weaker than Diamond.*
  5. __Diamond__
    *Stronger than Platinum but weaker than Legendary.*
  6. __Legendary__  
    *Highest possible rating.*

## Spells
  __[Description]__
  *Each class has three sets of spells for different weapon and element types
   and one default set for having no weapon.  Each set of spells has four different
   unique spells. Switching to a different weapon or element type will change your set
   of spells.*

## Enemy types
  *Stats {HP/ATK/DEF}*

### Beast (Tier 1) Takes full (normal dmg)  
  1. __Wolves__  
		*3 / 3 / 1*
  2. __Cougars__  
    *3 / 4 / 0*
 	3. __Bears__  
		*3 / 2 / 2*

### Bandits (Tier 2)  
  1. __Highway Bandit__  
		*20 / 4 / 2*
  2. __Rouge Knight - random triangle weapon__  
		*30 / 3 / 5*
  3. __Rogue Mage - Random element__  
		*20 / 7 / 0*

### Skeleton (Tier 3)  
  1. __Skeleton Warrior - random triange weapon__  
		*40 / 7 / 7*
  2. __Skeleton Mage - random element__  
		*30 / 15 / 0*
  3. __Skeleton Archer__
    *30 / 12 / 2*
  4. __Arch Lich - random element__  
		*50 / 8 / 5*

### Horrors (Tier 4)  
  1. __Deformed beast - random element__  
		*40 / 20 / 0*
  2. __Deformed humans - random element and weapon__  
		*60 / 10 / 10*
  3. __Other worldly horrors - random element and weapon__  
		*60 / 15 / 10*
  4. __Horror gate guarded - random element and weapon__  
		*100 / 10 / 15*

### Demon (Tier 5)
  1. __Fire Demon - Fire element__  
    *100 / 20 / 10*  
  2. __Nature Demon - Nature element__  
    *200 / 15 / 15*  
  3. __Water Demon - Water element__   
    *300 / 10 / 20*  
### The Demon (Tier 6)
  1. __Satan (final boss)__  
    *500 / 30 / 30*  

### Stages
  __[Description]__
  *Defeat enemies to collect their souls that will be used to move on further
  into the dungeon*


## Random Events
*Choose between two paths that will randomly decide your fate*
  1. __Heal event__
  2. __Beggar event__
  3. __Loot events__
  4. __Resting event__
  5. __Trap event__
  6. __Enemy event__
