## A YARA-rule by using Quick-Search-Algorithm


hello,
seccamp2017で作ったyaraのソースコードです。

アルゴリズムを変えたので、test3.cというのはクイックサーチアルゴリズムのプログラムです。
なんか色々ごちゃごちゃありますが、そのうち整理します笑
解説に関しては以下の通りです！
基本的なyaraの使い方も下にかいてあります！

test
when I have attended security-camp 2017, I have made to use Quick-Search yara program.<br>
it was adopt Qucik-Search algorithm.<br>

Computational Complexity<br>
To be keyword length:n, string length:s<br>

Native way :best O(n), bad(n*k)<br>
Automaton　way : best and bad O(n)<br>
Quick Search way: best O(n/k), bad O(n*k)<br>

test3.c is quick-search algorithm.<br>

this github is very disoder....lol <br>
I will be arrenement butifully ...someday<br>
so if you have occurred the question, please give me the e-mail<br>
mail: ykusama@sfc.keio.ac.jp<br>

thank you for all





[![Join the chat at https://gitter.im/VirusTotal/yara](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/VirusTotal/yara?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
[![Travis build status](https://travis-ci.org/VirusTotal/yara.svg)](https://travis-ci.org/VirusTotal/yara)
[![AppVeyor build status](https://ci.appveyor.com/api/projects/status/7glqg19w4oolm7pr?svg=true)](https://ci.appveyor.com/project/plusvic/yara)
[![Coverity status](https://scan.coverity.com/projects/9057/badge.svg?flat=1)](https://scan.coverity.com/projects/plusvic-yara)



## YARA in a nutshell

YARA is a tool aimed at (but not limited to) helping malware researchers to
identify and classify malware samples. With YARA you can create descriptions of
malware families (or whatever you want to describe) based on textual or binary
patterns. Each description, a.k.a rule, consists of a set of strings and a
boolean expression which determine its logic. Let's see an example:

```
rule silent_banker : banker
{
    meta:
        description = "This is just an example"
        threat_level = 3
        in_the_wild = true

    strings:
        $a = {6A 40 68 00 30 00 00 6A 14 8D 91}
        $b = {8D 4D B0 2B C1 83 C0 27 99 6A 4E 59 F7 F9}
        $c = "UVODFRYSIHLNWPEJXQZAKCBGMT"

    condition:
        $a or $b or $c
}
```

The above rule is telling YARA that any file containing one of the three strings
must be reported as *silent_banker*. This is just a simple example, more
complex and powerful rules can be created by using wild-cards, case-insensitive
strings, regular expressions, special operators and many other features that
you'll find explained in [YARA's documentation](http://yara.readthedocs.org/).

YARA is multi-platform, running on Windows, Linux and Mac OS X, and can be used
through its command-line interface or from your own Python scripts with the
yara-python extension.

If you plan to use YARA to scan compressed files (.zip, .tar, etc) you should
take a look at [yextend](https://github.com/BayshoreNetworks/yextend), a very
helpful extension to YARA developed and open-sourced by Bayshore Networks.

## Who's using YARA

* [ActiveCanopy](https://activecanopy.com/)
* [Adlice](http://www.adlice.com/)
* [BAE Systems](http://www.baesystems.com/home?r=ai)
* [Bayshore Networks, Inc.](http://www.bayshorenetworks.com)
* [Blue Coat](http://www.bluecoat.com/products/malware-analysis-appliance)
* [Blueliv](http://www.blueliv.com)
* [CrowdStrike FMS](https://github.com/CrowdStrike/CrowdFMS)
* [Cuckoo Sandbox](https://github.com/cuckoosandbox/cuckoo)
* [ESET](https://www.eset.com)
* [Fidelis XPS](http://www.fidelissecurity.com/network-security-appliance/Fidelis-XPS)
* [FireEye, Inc.](http://www.fireeye.com)
* [Fox-IT](https://www.fox-it.com)
* [FSF](https://github.com/EmersonElectricCo/fsf)
* [Guidance Software](http://www.guidancesoftware.com/endpointsecurity)
* [Heroku](https://heroku.com)
* [JASK](http://jask.io)
* [jsunpack-n](http://jsunpack.jeek.org/)
* [Kaspersky Lab](http://www.kaspersky.com)
* [Koodous](https://koodous.com/)
* [Laika BOSS](https://github.com/lmco/laikaboss)
* [Lastline, Inc.](http://www.lastline.com)
* [McAfee Advanced Threat Defense](http://mcafee.com/atd)
* [Metaflows](http://www.metaflows.com)
* [NBS System](https://www.nbs-system.com/)
* [osquery](http://www.osquery.io)
* [Payload Security](https://www.payload-security.com)
* [PhishMe](http://phishme.com/)
* [Picus Security](http://www.picussecurity.com/)
* [Radare2](http://rada.re)
* [Raytheon Cyber Products, Inc.](http://www.raytheoncyber.com/capabilities/products/sureview-threatprotection/)
* [ReversingLabs](http://reversinglabs.com)
* [root9B](https://www.root9b.com)
* [RSA ECAT](http://www.emc.com/security/rsa-ecat.htm)
* [SpamStopsHere](https://www.spamstopshere.com)
* [stoQ](http://stoq.punchcyber.com)
* [Symantec](http://www.symantec.com)
* [Tanium](http://www.tanium.com/)
* [Tenable Network Security](https://www.tenable.com/)
* [The DigiTrust Group](http://www.digitrustgroup.com/)
* [ThreatConnect](http://www.threatconnect.com)
* [ThreatStream, Inc.](http://threatstream.com)
* [Thug](https://github.com/buffer/thug)
* [Trend Micro](http://www.trendmicro.com)
* [VirusTotal Intelligence](https://www.virustotal.com/intelligence/)
* [VMRay](https://www.vmray.com/)
* [We Watch Your Website](http://www.wewatchyourwebsite.com/)
* [Websense](http://www.websense.com)
* [x64dbg](http://x64dbg.com)
* [YALIH](https://github.com/Masood-M/YALIH)
* [Scanii](https://scanii.com)

Are you using it? Want to see your site listed here?sl



