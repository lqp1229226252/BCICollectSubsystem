-- MySQL dump 10.13  Distrib 5.7.39, for Linux (x86_64)
--
-- Host: localhost    Database: WGB
-- ------------------------------------------------------
-- Server version	5.7.39-0ubuntu0.18.04.2

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Temporary table structure for view `conactsview`
--

DROP TABLE IF EXISTS `conactsview`;
/*!50001 DROP VIEW IF EXISTS `conactsview`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE VIEW `conactsview` AS SELECT 
 1 AS `id`,
 1 AS `name`,
 1 AS `phone`,
 1 AS `address`*/;
SET character_set_client = @saved_cs_client;

--
-- Temporary table structure for view `userview`
--

DROP TABLE IF EXISTS `userview`;
/*!50001 DROP VIEW IF EXISTS `userview`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE VIEW `userview` AS SELECT 
 1 AS `id`,
 1 AS `user_name`,
 1 AS `name`,
 1 AS `age`,
 1 AS `nation`,
 1 AS `sex`,
 1 AS `handedness`,
 1 AS `work_exp`,
 1 AS `edu_level`,
 1 AS `phone`,
 1 AS `address`,
 1 AS `contact_way`,
 1 AS `exercising_way`,
 1 AS `health`*/;
SET character_set_client = @saved_cs_client;

--
-- Final view structure for view `conactsview`
--

/*!50001 DROP VIEW IF EXISTS `conactsview`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`anqsl`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `conactsview` AS select `conacts`.`id` AS `id`,`conacts`.`name` AS `name`,`conacts`.`phone` AS `phone`,`conacts`.`address` AS `address` from `conacts` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `userview`
--

/*!50001 DROP VIEW IF EXISTS `userview`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`anqsl`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `userview` AS select `user`.`id` AS `id`,`user`.`user_name` AS `user_name`,`user`.`name` AS `name`,`user`.`age` AS `age`,`user`.`nation` AS `nation`,`user`.`sex` AS `sex`,`user`.`handedness` AS `handedness`,`user`.`work_exp` AS `work_exp`,`user`.`edu_level` AS `edu_level`,`user`.`phone` AS `phone`,`user`.`address` AS `address`,`user`.`contact_way` AS `contact_way`,`user`.`exercising_way` AS `exercising_way`,`user`.`health` AS `health` from `user` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-10-21  5:05:51
