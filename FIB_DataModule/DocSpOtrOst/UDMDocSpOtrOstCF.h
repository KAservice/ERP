#ifndef UDMDocSpOtrOstCFH                  
#define UDMDocSpOtrOstCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocSpOtrOstCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocSpOtrOstCF();                                                           
   ~TDMDocSpOtrOstCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
