#ifndef __DEFINE__
#define __DEFINE__

//
// based on:
// - https://github.com/Ytfarc/sfall1/blob/master/Source/Define.h
//

#define no_proc            (0)
#define start_proc         (1)
#define spatial_proc       (2)
#define description_proc   (3)
#define pickup_proc        (4)
#define drop_proc          (5)
#define use_proc           (6)
#define use_obj_on_proc    (7)
#define use_skill_on_proc  (8)
#define use_ad_on_proc     (9)
#define use_disad_on_proc  (10)
#define talk_proc          (11)
#define critter_proc       (12)
#define combat_proc        (13)
#define damage_proc        (14)
#define map_enter_proc     (15)
#define map_exit_proc      (16)
#define create_proc        (17)
#define destroy_proc       (18)
#define barter_init_proc   (19)
#define barter_proc        (20)
#define look_at_proc       (21)
#define timed_event_proc   (22)
#define map_update_proc    (23)

#define TTRAIT_PERK        (0)
#define TTRAIT_OBJECT      (1)
#define TTRAIT_TRAIT       (2)

#define PERK_bonus_awareness     (0)
#define PERK_bonus_hth_attacks   (1)
#define PERK_bonus_hth_damage    (2)
#define PERK_bonus_move          (3)
#define PERK_bonus_ranged_damage (4)
#define PERK_bonus_rate_of_fire  (5)
#define PERK_earlier_sequence    (6)
#define PERK_faster_healing      (7)
#define PERK_more_criticals      (8)
#define PERK_night_vision        (9)
#define PERK_presence            (10)
#define PERK_rad_resistance      (11)
#define PERK_toughness           (12)
#define PERK_strong_back         (13)
#define PERK_sharpshooter        (14)
#define PERK_silent_running      (15)
#define PERK_survivalist         (16)
#define PERK_master_trader       (17)
#define PERK_educated            (18)
#define PERK_healer              (19)
#define PERK_fortune_finder      (20)
#define PERK_better_criticals    (21)
#define PERK_empathy             (22)
#define PERK_slayer              (23)
#define PERK_sniper              (24)
#define PERK_silent_death        (25)
#define PERK_action_boy          (26)
#define PERK_mental_block        (27)
#define PERK_lifegiver           (28)
#define PERK_dodger              (29)
#define PERK_snakeater           (30)
#define PERK_mr_fixit            (31)
#define PERK_medic               (32)
#define PERK_master_thief        (33)
#define PERK_speaker             (34)
#define PERK_heave_ho            (35)
#define PERK_friendly_foe        (36)
#define PERK_pickpocket          (37)
#define PERK_ghost               (38)
#define PERK_cult_of_personality (39)
#define PERK_scrounger           (40)
#define PERK_explorer            (41)
#define PERK_flower_child        (42)
#define PERK_pathfinder          (43)
#define PERK_animal_friend       (44)
#define PERK_scout               (45)
#define PERK_mysterious_stranger (46)
#define PERK_ranger              (47)
#define PERK_quick_pockets       (48)
#define PERK_smooth_talker       (49)
#define PERK_swift_learner       (50)
#define PERK_tag                 (51)
#define PERK_mutate              (52)
#define PERK_add_nuka            (53)
#define PERK_add_buffout         (54)
#define PERK_add_mentats         (55)
#define PERK_add_psycho          (56)
#define PERK_add_radaway         (57)
#define PERK_weapon_long_range   (58)
#define PERK_weapon_accurate     (59)
#define PERK_weapon_penetrate    (60)
#define PERK_weapon_knockback    (61)
#define PERK_armor_powered       (62)
#define PERK_armor_combat        (63)

#define OBJECT_AI_PACKET   (5)
#define OBJECT_TEAM_NUM    (6)
#define OBJECT_CUR_ROT     (10)
#define OBJECT_VISIBILITY  (666)
#define OBJECT_CUR_WEIGHT  (669)

#define TRAIT_fast_metabolism (0)
#define TRAIT_bruiser         (1)
#define TRAIT_small_frame     (2)
#define TRAIT_one_hander      (3)
#define TRAIT_finesse         (4)
#define TRAIT_kamikaze        (5)
#define TRAIT_heavy_handed    (6)
#define TRAIT_fast_shot       (7)
#define TRAIT_bloody_mess     (8)
#define TRAIT_jinxed          (9)
#define TRAIT_good_natured    (10)
#define TRAIT_drug_addict     (11)
#define TRAIT_drug_resistant  (12)
#define TRAIT_sex_appeal      (13)
#define TRAIT_night_person    (14)
#define TRAIT_gifted          (15)

#define STAT_st                    (0)
#define STAT_pe                    (1)
#define STAT_en                    (2)
#define STAT_ch                    (3)
#define STAT_iq                    (4)
#define STAT_ag                    (5)
#define STAT_lu                    (6)
#define STAT_max_hit_points        (7)
#define STAT_max_move_points       (8)
#define STAT_ac                    (9)
#define STAT_unused                (10)
#define STAT_melee_dmg             (11)
#define STAT_carry_amt             (12)
#define STAT_sequence              (13)
#define STAT_heal_rate             (14)
#define STAT_crit_chance           (15)
#define STAT_better_crit           (16)
#define STAT_dmg_thresh            (17)
#define STAT_dmg_thresh_laser      (18)
#define STAT_dmg_thresh_fire       (19)
#define STAT_dmg_thresh_plasma     (20)
#define STAT_dmg_thresh_electrical (21)
#define STAT_dmg_thresh_emp        (22)
#define STAT_dmg_thresh_explosion  (23)
#define STAT_dmg_resist            (24)
#define STAT_dmg_resist_laser      (25)
#define STAT_dmg_resist_fire       (26)
#define STAT_dmg_resist_plasma     (27)
#define STAT_dmg_resist_electrical (28)
#define STAT_dmg_resist_emp        (29)
#define STAT_dmg_resist_explosion  (30)
#define STAT_rad_resist            (31)
#define STAT_poison_resist         (32)
#define STAT_age                   (33)
#define STAT_gender                (34)
#define STAT_current_hp            (35)
#define STAT_current_poison        (36)
#define STAT_current_rad           (37)

#define PCSTAT_unspent_skill_points (0)
#define PCSTAT_level                (1)
#define PCSTAT_experience           (2)
#define PCSTAT_reputation           (3)
#define PCSTAT_karma                (4)

#define SKILL_SMALL_GUNS     (0)
#define SKILL_BIG_GUNS       (1)
#define SKILL_ENERGY_WEAPONS (2)
#define SKILL_UNARMED_COMBAT (3)
#define SKILL_MELEE          (4)
#define SKILL_THROWING       (5)
#define SKILL_FIRST_AID      (6)
#define SKILL_DOCTOR         (7)
#define SKILL_SNEAK          (8)
#define SKILL_LOCKPICK       (9)
#define SKILL_STEAL          (10)
#define SKILL_TRAPS          (11)
#define SKILL_SCIENCE        (12)
#define SKILL_REPAIR         (13)
#define SKILL_SPEECH         (14)
#define SKILL_BARTER         (15)
#define SKILL_GAMBLING       (16)
#define SKILL_OUTDOORSMAN    (17)

#endif // __DEFINE__ //