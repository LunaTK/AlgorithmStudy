class Solution:
    def isValid(self, s: str) -> bool:
        paren_list = []
        for i in range(len(s)):
            paren_list.append(s[i])
            
        cnt = 0
        for i in range(len(paren_list)):
            if i == 0 and paren_list[i] in [')', '}', ']']:
                return False
            
            if paren_list[i-cnt*2] == ')':
                if paren_list[i-cnt*2-1] == '(':
                    del paren_list[i-cnt*2]
                    del paren_list[i-cnt*2-1]
                    cnt = cnt+1
                    
            elif paren_list[i-cnt*2] == '}':
                if paren_list[i-cnt*2-1] == '{':
                    del paren_list[i-cnt*2]
                    del paren_list[i-cnt*2-1]
                    cnt = cnt+1
                
            elif paren_list[i-cnt*2] == ']':
                if paren_list[i-cnt*2-1] == '[':
                    del paren_list[i-cnt*2]
                    del paren_list[i-cnt*2-1]
                    cnt = cnt+1
                
        
        if len(paren_list) == 0:
            return True
        else:
            return False
