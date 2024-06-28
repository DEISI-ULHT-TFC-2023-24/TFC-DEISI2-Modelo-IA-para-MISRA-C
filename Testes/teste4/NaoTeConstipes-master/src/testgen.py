#!/usr/bin/python

import sys
import subprocess
from random import seed
from random import randint
import re
import os
import json

# seed random number generator
seed(7)

def rep_int(frase):
	pholders = re.findall(r'<i:[-+]?[0-9]+:[-+]?[0-9]+>', frase)
	for ph in pholders:
		start_int = int(re.search(r':[-+]?[0-9]+:', ph).group()[1:-1])
		end_int = int(re.search(r':[-+]?[0-9]+>', ph).group()[1:-1])
		rnd_int = randint(start_int,end_int)
		frase = frase.replace(ph, str(rnd_int), 1)
	return frase

# generate a random number in hex format between min and max. Min and Max are in decimal
def rep_hex(frase):
	pholders = re.findall(r'<x:[-+]?[0-9]+:[-+]?[0-9]+>', frase)
	for ph in pholders:
		start_int = int(re.search(r':[-+]?[0-9]+:', ph).group()[1:-1])
		end_int = int(re.search(r':[-+]?[0-9]+>', ph).group()[1:-1])
		rnd_int = randint(start_int,end_int)
		frase = frase.replace(ph, hex(rnd_int), 1)
	return frase	

# generate a random number in octal format between min and max. Min and Max are in decimal
def rep_oct(frase):
	pholders = re.findall(r'<o:[-+]?[0-9]+:[-+]?[0-9]+>', frase)
	for ph in pholders:
		start_int = int(re.search(r':[-+]?[0-9]+:', ph).group()[1:-1])
		end_int = int(re.search(r':[-+]?[0-9]+>', ph).group()[1:-1])
		rnd_int = randint(start_int,end_int)
		frase = frase.replace(ph, oct(rnd_int), 1)
	return frase	



def rep_char(frase):
	pholders = re.findall(r'<c:.:.>', frase)
	for ph in pholders: 
		start_char = ord(re.search(r':.:', ph).group()[1])
		end_char = ord(re.search(r':.>', ph).group()[1])
		rnd_int = randint(start_char,end_char)
		frase = frase.replace(ph, str(chr(rnd_int)), 1)
	return frase



def check_output(command, cwd):
	process = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
							   universal_newlines=True, cwd=cwd)
	output = process.communicate()
	retcode = process.poll()
	return output, retcode


testList = list()


print ('Number of arguments:' + str(len(sys.argv)) + ' arguments.')
print ('Argument List:' +  str(sys.argv))

if len(sys.argv) < 5:
	print("Usage: python testgen.py <input_file>.json <path_to_exec_file> <output_folder> <file_prefix>")
	print("Example: python testgen.py example.json ./src ./tests LP12020EX2")
	exit(1)

try:
	with open(sys.argv[1], 'r') as f:

		data = json.load(f)

except IOError as e:
	print("Couldn't open or write to file (%s)." % e)
	exit()

f.close()

i = 0
for test in data:

	context = {}




	print("reading test " + str(i))

	name = os.path.join(sys.argv[3], sys.argv[4] + '_test_' + str(i) +'.in')
	name_out = os.path.join(sys.argv[3], sys.argv[4] + '_test_' + str(i) +'.out')
	#name_info = os.path.join(sys.argv[3], sys.argv[4] + '_test_' + str(i) +'.info')


	if "name" in test:
		context.update({'name': test['name']})

	if "mandatory" in test:
		context.update({'mandatory': test['mandatory']})

	if "weight_pct" in test:
		context.update({'weight_pct': test['weight_pct']})

	if "run_arguments" in test:
		context.update({'run_arguments': test['run_arguments']})
		run = test['run_arguments']
		run = run.replace('<cwd>', os.getcwd(), 1)
	else:
		run = " "


	if "view_diff" in test:
		context.update({'view_diff': test['view_diff']})

	if "view_args" in test:
		context.update({'view_args': test['view_args']})

	if "view_error" in test:
		context.update({'view_error': test['view_error']})

	if "description" in test:
		context.update({'description': test['description']})


	try:
		with open(name, 'w') as f:
			context.update({'input': list()})

			for line in test['input']:
				line = rep_char(line)
				line = rep_int(line)
				line = rep_hex(line)
				line = rep_oct(line)

#				while 1:
##					v = line.replace('<h>', str(hex(randint(0,65535))), 1)
#					v = v.replace('<i>', str(randint(-32768,32767)), 1)
#					v = v.replace('<d>', str(randint(1,8)), 1)
#					v = v.replace('<c>', str(chr(randint(65,72))), 1)
#					v = v.replace('<u>', str(randint(1,3)), 1)


#					if v == line:
#						break
#					line = v
				f.write(line + '\n')
				print(line)
				context['input'].append(line)
		f.close()
	except IOError as e:
		print("Couldn't open or write to file (%s)." % e)
		exit()


#	try:
#		with open(name_info, 'w') as f:
#			test_i = {'info' : test}
#			f.write(json.dumps(test_i, indent=4))
#		f.close()
#	except IOError as e:
#		print("Couldn't open or write to file (%s)." % e)
#		exit()

	

	cmd = sys.argv[2] + " " + run + ' < ' + name + ' > ' + name_out
	print(cmd)
	output, ret = check_output(cmd, os.getcwd())
	i += 1


	# Open a file
	fo = open(name_out, "r")
	context.update({'output': fo.readlines()})
	fo.close()
	
	testList.append(context)



try:
	with open("contest.nfo", 'w') as f:
		f.write(json.dumps(testList, indent=4))
		f.close()
except IOError as e:
	print("Couldn't open or write to file (%s)." % e)
	exit()
