#Puppet class

class packages {

#This part will install the following vim curl git
package { 'vim' :
  require => Exec['yum update'],
  ensure => installed,
  enable => true,
}

package { 'curl' :
  require => Exec['yum update'],
  ensure => installed,
  enable => true,
}

package { 'git' :
  require => Exec['yum update'],
  ensure => installed,
  enable => true,
}

#To ensure the execution of the wget command
package { 'wget' :
  ensure => running,
}
#To make sure that the installed package will be detected if successfully installed and running
service { 'vim' :
  ensure => running,
  enable => true,
}

service { 'git' :
  ensure => running,
  enable => true,
}

service { 'curl' :
  ensure => running,
  enable => true,
}
#Part which i created a user
user { 'monitor' :
        ensure => 'installed',
        managehome => true,
        home => '/home/monitor',
        shell => '/bin/bash',
        }
#This stage is the part where the code will download the bash script i created on Step#1 which is namely voyagertest1.sh i used the following to create the link which is github raw and wget
exec {'memory_check' :
	command => "usr/bin/wget -r  https://raw.githubusercontent.com/ramercado/VoyagerTask/master/voyagertest1.sh",
	create => "/home/monitor/script",
}
#This will create the directory namely memory_check where the downloaded files will be place
file {'/home/monitor/script' :
	require => Exec["memory_check"],
}
#This part is the part which will create a softlink named my_memory_check which will directly point to the script... 
exec {'my_memory_check' :
	create => "/home/monitor/src",
}

file {'/home/monitor/src' :
	ensure => 'link',
	target => '/home/monitor/script/memory_check/ramercado/VoyagerTask/master/voyagertest1.sh'
}

#Crontab that will run '/home/monitor/script/memory_check/ramercado/VoyagerTask/master/voyagertest1.sh' every 10 mins....
cron { '/home/monitor/script/memory_check/ramercado/VoyagerTask/master/voyagertest1.sh' :   
   command => "'/home/monitor/script/memory_check/ramercado/VoyagerTask/master/voyagertest1.sh'",   
   user    => monitor,
   hour    => '*',   
   minute  => '*/10',
   require => File['/home/monitor/script/memory_check/ramercado/VoyagerTask/master/voyagertest1.sh']
}

 class { 'timezone':
        timezone => 'PHT',
    }

file {'/etc/sysconfig/network' :
  ensure => '/etc/sysconfig/network',
  networking => "yes",
  hostname => "bpx.server.local",
  gatewaydev => "eth0",
  forward_ipv4 =>"yes",
}
}

