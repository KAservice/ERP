#ifndef UDMDocKorrVsCFH                  
#define UDMDocKorrVsCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocKorrVsCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocKorrVsCF();                                                           
   ~TDMDocKorrVsCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
