import numpy as np
from os import system
from time import sleep

class GameOfLife:
	def __init__(self):
		self.boardSize = 20
		self.delay = 1
		self.blankPixel = '-'
		self.livePixel = 'O'
		self.pattern = 0
		self.display_buffer = 0
		self.left_pad = 5
		self.top_pad = 5

	def setBoardSize(self, boardSize = 20):
		self.boardSize = boardSize

	def setDelay(self, delay = 0.1):
		self.delay = delay

	def setBlankPixel(self, blankPixel = '-'):
		self.blankPixel = blankPixel

	def setLivePixel(self, livePixel = 'O'):
		self.livePixel = livePixel

	def setPattern(self, pattern):
		self.pattern = pattern

	def setPadding(self, left, top):
		self.left_pad = left
		self.top_pad = top

	def bufferToTerminal(self):
		system('clear')
		#bufer = self.display_buffer.astype(str)
		for line in self.display_buffer:
			for pixel in line:
				#print(pixel)
				if(pixel==0.0):
					print(self.blankPixel,end='')
				#	print("-",end='')
				else:
					print(self.livePixel,end='')
			print()
		sleep(self.delay) # stop for matching Frame rate

	def updateBuffer(self):
		copy_buffer = self.display_buffer.copy()
		for row in range(self.boardSize):
			for col in range(self.boardSize):
				pixel = self.display_buffer[row][col]
				pixel_neighbours = np.zeros((3,3)) 
				rows = [0,3]
				cols = [0,3]
				if(row == 0):
					rows[0] = 1
				elif(row == self.boardSize-1): # for handeling corner cases in rows
					rows[1] = 2

				if(col == 0):
					cols[0] = 1
				elif(col == self.boardSize-1): # for handeling corner cases in columns
					cols[1] = 2

				for ro in range(rows[0], rows[1]):
					for co in range(cols[0], cols[1]):
						pixel_neighbours[ro][co] = self.display_buffer[row-1+ro][col-1+co]
				alive_neighbours = np.count_nonzero(pixel_neighbours)
				if(pixel == 0 and alive_neighbours == 3):
					copy_buffer[row][col] = 1 # make the cell alive
				elif(pixel==1):
					alive_neighbours -= 1
					if(3 < alive_neighbours or alive_neighbours < 2 ):
						copy_buffer[row][col] = 0 # die due to over poplulation or under population

		self.display_buffer = copy_buffer
					



	def live(self):
		self.display_buffer = np.zeros((self.boardSize,self.boardSize))
		self.display_buffer[self.left_pad:self.left_pad+self.pattern.shape[0], 
							self.top_pad:self.top_pad+self.pattern.shape[1]] = self.pattern
		#print(self.display_buffer)
		#self.bufferToTerminal()
		while(1):
			self.bufferToTerminal()
			self.updateBuffer()
