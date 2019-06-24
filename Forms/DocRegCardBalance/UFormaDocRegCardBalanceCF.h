#ifndef UFormaDocRegCardBalanceCFH                  
#define UFormaDocRegCardBalanceCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocRegCardBalanceCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocRegCardBalanceCF();                                                           
   ~TFormaDocRegCardBalanceCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
