#ifndef UDMObjectBaseGrpCFH                  
#define UDMObjectBaseGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMObjectBaseGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMObjectBaseGrpCF();                                                           
   ~TDMObjectBaseGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
