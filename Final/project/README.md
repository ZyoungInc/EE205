# Soul Quest

# Usage Notes
> Before running the game, scale your terminal window before starting the game.
> This game utilizes the ncurses library. Please install ncurses using
> "sudo apt-get install libncurses-dev" before running the game.
> Since ncurses takes in the size of the window, scaling after the game has
> started will result in the distortion of the interface.

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
    *Strong against Sword but weak against Axe.*
  2. __Sword__  
    *Strong against Axe but weak against Lance.*
  3. __Axe__  
    *Strong against Lance but weak against Sword.*

## Weapon rarity
  1. __Bronze__  
    *Lowest possible rating.*
  2. __Silver__  
    *Stronger than Bronze but weaker than Gold.*
  3. __Gold__  
    *Stronger than Silver but weaker than Platinum.*
  4. __Platinum__  
    *Stronger than Platinum but weaker than Legendary.*
  5. __Legendary__  
    *Highest possible rating.*

## Spells
  __[Description]__

## Enemy types
  *Stats {HP/ATK/DEF}*

### Beast (lowest tier) Takes full (normal dmg)  
  1. __Wolves__  
		*5 / 2 / 0*
  2. __Cougars__  
    *3 / 4 / 0*
 	3. __Bears__  
		*5 / 2 / 2*

### Bandits (Tier 1)  
  1. __Highwaymen - full dmg__  
		*8 / 4 / 2*
  2. __Rouge Knights - random triangle weapon__  
		*10 / 4 / 4*
  3. __Rogue Mage - Random element__  
		*8 / 6 / 0*

### Skeleton (Tier 2)  
  1. __Regular__  
		*14 / 6 / 2*
  2. __Mage // arhcer - High atk/ low hp/def__  
		*12 / 8 / 0*
  3. __Lich (controller)__  
		*18 / 8 / 8*

### Horrors (Tier 3)  
  1. __Deformed beast__  
		*16 / 6 / 0*
  2. __Deformed humans__  
		*18 / 6 / 6*
  3. __Other worldly horrors__  
		*20 / 10 / 10*
  4. __Horror gate guarded // Random weapon and element__  
		*40 / 10 / 15*

### Demon (Boss)
  1. __Fire Demon__  
    *40 / 20 / 10*  
    Fire element
  2. __Nature Demon__  
    *50 / 15 / 15*  
    Nature element
  3. __Water Demon__   
    *60 / 10 / 20*  
    Water element
  4. __Eo Tem (final boss)__  
    *100 / 20 / 20*  
    No element  
    Will OTK on 20th Turn

## Branching paths
  1. __Two random events__
	2. __Regular mobs__
	3. __Boss__
	4. __Hidden event__  
		a. High chance of event but boss and regular is possible  
		b. Trader  
		c. Shrine (give up gold for item?)  
		d. Lost (lose 3 progress)  
		e. Begger  
		f. Nothing  
	5. __Chest (mimic chance)__
		*Might be guarded (choice to fight or flee)*

## Random encounters
  __[Description]__
