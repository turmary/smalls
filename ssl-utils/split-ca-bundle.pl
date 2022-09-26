#!/usr/bin/perl -w

# from https://stackoverflow.com/questions/23644473/how-can-i-split-a-ca-certificate-bundle-into-separate-files

# -------
# Split "certificate bundles" like those found in /etc/pki/tls/certs into
# individual files and append the X509 cleartext description to each file.
#
# The file to split is given on the command line or piped via STDIN.
#
# Files are simply created in the current directory!
#
# Created files are named "certificate.XX" or "trusted-certificate.XX",
# with XX an index value.
#
# If a file with the same name as the output file already exists, it is not
# overwritten. Instead a new name with a higher index is tried.
#
# This works for bundles of both trusted and non-trusted certificates.
#
# See http://tygerclan.net/?q=node/49 for another program of this kind,
# which sets the name of the split-off files in function of the subject
# -------

my @lines = <> or die "Could not slurp: $!";

my $state = "outside"; # reader state machine state
my $count = 0;         # index of the certificate file we create
my $fh;                # file handle of the certificate file we create
my $fn;                # file name of the certificate file we create
my $trusted;           # either undef or "TRUSTED" depend on type of certificate

for my $line (@lines) {
   chomp $line;
   if ($state eq "outside") {
      if ($line =~ /^(-----BEGIN (TRUSTED )?CERTIFICATE-----)\s*$/) {
         my $marker  = $1;
         $trusted    = $2;
         $state      = "inside";
         my $created = 0;
         my $prefix  = "";
         if ($trusted) {
            $prefix = "trusted-"
         }
         while (!$created) {
            $fn = "${prefix}certificate.$count";
            $count++;
            if (-f $fn) {
               # print STDERR "File '$fn' exists; increasing version number to $count\n";
            }
            else {
               print STDERR "Certificate data goes to file '$fn'\n";
               open($fh,">$fn") || die "Could not create file '$fn': $!\n";
               $created = 1;
               print $fh "$marker\n"
            }
         }
      }
      else {
         print STDERR "Skipping line '$line'\n"
      }
   }
   else {
      if ($line =~ /^(-----END (TRUSTED )?CERTIFICATE-----)\s*$/) {
         my $marker       = $1;
         my $trustedCheck = $2;
         if (!((($trusted && $trustedCheck) || (!$trusted && !$trustedCheck)))) {
            die "Trusted flag difference detected\n"
         }
         $state = "outside";
         print $fh "$marker\n";
         print STDERR "Closing file '$fn'\n";
         close $fh;
         # Append x509 cleartext output by calling openssl tool
         `openssl x509 -noout -text -in '$fn' >> '$fn'`;
         if ($? != 0) {
            die "Could not run 'openssl x509' command: $!\n";
         }
      }
      else {
         print $fh "$line\n"
      }
   }
}

if ($state eq "inside") {
   die "Last certificate was not properly terminated\n";
}
