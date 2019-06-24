#ifndef UFormaSpiskaSprDogovorCFH                  
#define UFormaSpiskaSprDogovorCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprDogovorCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprDogovorCF();                                                           
   ~TFormaSpiskaSprDogovorCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
