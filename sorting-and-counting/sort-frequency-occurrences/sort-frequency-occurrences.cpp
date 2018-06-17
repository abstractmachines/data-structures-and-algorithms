/* Fog Creek Solution
by Amanda Falke

Problem statement: Sort characters in a given string by frequency of occurrences
without repeated items. Strip off all characters after '_' underscore. Print
in descending order by frequency/occurrence.

-> Design:

	-> High Level Algorithm: Overview

			1. Hash Unordered Set inserts in amortized constant O(1), linear O(n) time.
			2. count() frequency / number occurrences for each character; store
				in ordered Map, ordered by frequency as key, and value as number itself.
				Ordered Unique Map (Dictionary) will insert() in-order, unique keys,
				in amortized constant O(1), logarithmic O(log n) time.
			3. Ensure that Map is ordered in descending order (reverse iteration)
			4. Print. To drop all characters including and after the underscore '_'
				simply use a while loop and a boolean.

	-> Data Structures: ADT implementations

			C++ Containers; similar to Java Collections.

				C++ Standard Library Associative Data Structures:

			• Ordered Map:
				unique keys, insert by order of occurrence using count() of Set

				The C++ ordered_ structures are implemented with red + black trees.
				Red and black trees are balanced trees, so they generally have
				temporal complexity of O( log n ) for operations, as is common with
				balanced binary structures.

			• Unordered (hash) MultiSet (Bag):
				non-unique keys, insert all data and count()

	-> Design Advantages:
			1. Hashing data into an unordered set is fine for this data size
			2. Using collections means for quick prototyping,
			3. Using collections means less testing required for boundary/edge cases
			4. Balanced binary red and black trees are pretty performant structures;
				they're used in Linux scheduler and RTOS, so the tree part is good

	-> Design Disadvantages:
			1. Hashing data into an unordered set is not fine for larger data sets,
			so design doesn't really scale
			2. Using collections may be overbuilding the solution
			3. Solution does not unit test

-> Edge cases not explicitly covered:
	- stable sort: should order be preserved for equal numbers of permutations?
	- 0 items (this is covered by C++ Containers)

	- Amanda Falke

	*/


#include <iostream>
#include <unordered_set>
#include <array>
#include <map>

/* Class interface */

class freqSort
{
public:
	freqSort(std::string & s1) : m_s1(s1) {}

	std::unordered_multiset<char> insertHash(std::string & s1);

	void hashCountToMap(std::unordered_multiset<char> & hashCount);

	void printMap();

	~freqSort();

private:
	std::string m_s1;
	std::map<int,char> m_map;

};

/* Class Methods */

 std::unordered_multiset<char> freqSort::insertHash(std::string & s1)
{
	std::unordered_multiset<char> hashCount;
	std::string::iterator iterStr;

	for( iterStr = m_s1.begin(); iterStr != m_s1.end(); ++iterStr)
	{
		hashCount.insert(*iterStr);
	}
	return hashCount;
}

void freqSort::hashCountToMap(std::unordered_multiset<char> & hashCount)
{
	std::unordered_multiset<char>::iterator iterHash;

	for( iterHash = hashCount.begin(); iterHash != hashCount.end(); ++iterHash)
	{
		m_map.insert(std::pair<int, char>
			(hashCount.count(*iterHash),*iterHash));
	}
}

void freqSort::printMap()
{
	std::cout<<"\nFog Creek Solution:\n";

	std::string::iterator iterStr;

	std::map<int,char>::reverse_iterator iterMapUniqueR = m_map.rbegin();

	bool notUnderScore = true;

	while(notUnderScore && iterMapUniqueR != m_map.rend())
	{
		if( iterMapUniqueR->second == '_')
		{
			notUnderScore = false;
		}
		else
		{
			std::cout << iterMapUniqueR->second;
			++iterMapUniqueR;
		}
	}
	std::cout << std::endl;
}

freqSort::~freqSort()
{}


#define RANGE 50

int main()
{
	std::string s1 = "hayjfltwmnlstaddvdkabpggxpcbmykiymbyphllzozvwjlkqrmaoxnsxqxjhvyrjykaddsoedcyitmevubhgelbmrtk_kxdizfgagidqvbvqrkhwscpenkdqatrcrhbucwmsv_qbygnjsydpr_mqftjviinseckyllydrbmsmyjaszwkdhnpjtk_awdokmpx_fzekzkttovqlfkqvwjbexvzwlnzaqwg_pqlorsmb_mavbuegnsvxptvbgcvairgdgsccac_ug_hbnkbu_svcbrjewiloukndywehdopjckulwwidrycoxsrpngacezescjtcutprmybxdivulcn_znajvbauio_jyahxxnyeyyznkoosgucjlzyqsptpbucirirywbpryjpktw_vl_unycyosq__alklnzv_qkpslqckzmuqbqfjiztsmskqdyxshhxkslvwx_bhaa_opivrqiandjfeyvowrnyysfaem_cgcvxuohpo__umqvbuqnrtcyijtrqsrfjpglsenwypljqixyjvkhogujuljtlowqghlwoonctrkcfwbzqqtqtmzef_elmbybryfiego_jknatrcrtecihdjsjzsytgpcomxkyduygnivcnq_gftnoc_tktdzuubehdjagd_caudrtgujkjzmhxdpvqsg_wyemsrvsdweyclxyhpqeeaphsyhahbbguogsuxsgtzaxktglhxg_xzeqjgmzhpmwfzwpufnrvdnkoyyrdqiwvxflndssbmanersenhltqtmvcmexdusczopalyxgqmopkedsvoszbu_sefquucivicerrnigkutzdojtnqtrfmocyjqs_b_eiqoncrudjccjnwhkjmmaanjsvkycryhxyyhimiebzoukiffcabhlujcwzfnhzlnhdvxyfxarcsqqjwgtbcugqftxrtqrspmpzczbrxpmrlqjqvqaylgvfhxezasdfrarlfxfrbofetptkljmztwvpwrswhmxhsny_bmlkxvyp_pendkcovvsfgkpjirrt_yhue_tgvkggz_shj_aldhfrvcfqxktkxyafaltwqzxoliocjitcikomih_mgygwvxvupgstjpfzbajdmjulbq_trsorfhfpulxnvdeoavcradzphqlngfi_on_kvllspucpxdamnws_ewgxalrlajoeaxxqqondjygfvqfa_ieuuemlozh_qyktxpypmmgou_izoroouiisnpsquplvapnqrmrecjilm_esnsz_steohcisskjioezirv_wlmoipuevrtwthybtrjqpuhuoacmnakhbikccacxb_eicdzwgwfmcdqet_fjum_zkbcokewropykow_cmfkpwuagxgxyfohejmxasb_lzxyzax_bgzjxsb_ollvzqwpyyndezpitwzdeeqthmrhqrhpzwxvdvliycsjiueoxrevkx_gjtpiowhpnit_rdwkocfxvivkfqkom_tjoimirz_ypyufouphocswbzfdprbiirfntvxtvytxgzwjaysxhptbenatxiaxwutrmiwbifqmpkwpmzmlkfzqnprskfsuvnphrbxysufcckssxwcbvapxbkfmum_meucimvshsawiucmimicnwnptynlghaeaaxtopadocumadecakteiw_ckczsvctsjwbaboqkzq_eouxfaiyexmf_iyrdjrkiuuudseoiuitxiyzwctiwgqwokiygfjzdbtimbpgfwypvtwkrgmcevfhqsekybgylzdvohlkwozsvxtkscuejhfjiwcummauh_lufqovxdwamlzfbr_uuquguwyplombdncgwaujpt_zsjziueozsblsxbjhgvzkuitdxaaxoxzm_akqgkulphkxdy_ttwrkxc_vmzqjelfiytessl_dxqitnlrocrmrmdcbudfxehd_wvxkjarnizentw_zoghv_iqjjgssfxeb_gbcu_ewymrelnpmpkteoibldnp_mtygdgauicswadrkagqeglugfa_fgv_oadajyqlsjjunvd_elotxznhrscujaljcqmm_ltlgdhazmzmppniqrs_ovmrioeouyrcuooso_mcuhfqvhtj_eoiomqsstpfrcmhxrrohkgyrdgeaamcbpghuduanwkuafuxbrvmpczqmwrzlur_fslnqbiew_nluucoyyn_yxviekfzmki_lqnijumpdbyptuvthgcvpkqshcs_abxwndxssacqxvbgcunoouhtlnkhlfefztckwntbomtralhdfvatdpyvojwgfjtrtwgwpdgbkh_wauyeda_aopit";

	freqSort fogCreekClass(s1);

	std::unordered_multiset<char> hashCount;

	hashCount = fogCreekClass.insertHash(s1);

	fogCreekClass.hashCountToMap(hashCount);

	fogCreekClass.printMap();

	return 0;
}
